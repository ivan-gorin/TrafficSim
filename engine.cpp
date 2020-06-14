#include "engine/engine.h"
#include <algorithm>
#include <cmath>
#include <limits>
#include <iostream>
#include <memory>

#include <ctime>
namespace traffic_model {

    Engine::Engine(const std::string &configFile, int threadNum) : threadNum(threadNum), startBarrier(threadNum + 1),
                                                                   endBarrier(threadNum + 1) {
        for (int i = 0; i < threadNum; i++) {
            threadVehiclePool.emplace_back();
            threadRoadPool.emplace_back();
            threadIntersectionPool.emplace_back();
            threadDrivablePool.emplace_back();
        }
        bool success = loadConfig(configFile);
        if (!success) {
            std::cerr << "load config failed!" << std::endl;
        }

        for (int i = 0; i < threadNum; i++) {
            threadPool.emplace_back(&Engine::threadController, this,
                                    std::ref(threadVehiclePool[i]),
                                    std::ref(threadRoadPool[i]),
                                    std::ref(threadIntersectionPool[i]),
                                    std::ref(threadDrivablePool[i]));
        }

    }


    bool Engine::loadConfig(const std::string &configFile) {
        rapidjson::Document document;
        if (!readJsonFromFile(configFile, document)) {
            std::cerr << "cannot open config file!" << std::endl;
            return false;
        }

        if (!document.IsObject()) {
            std::cerr << "wrong format of config file" << std::endl;
            return false;
        }

        try {
            interval = getJsonMember<double>("interval", document);
            warnings = false;
            rlTrafficLight = getJsonMember<bool>("rlTrafficLight", document);
            laneChange = getJsonMember<bool>("laneChange", document, false);
            seed = getJsonMember<int>("seed", document);
            rnd.seed(seed);
            dir = getJsonMember<const char*>("dir", document);
            std::string roadnetFile = getJsonMember<const char*>("roadnetFile", document);
            std::string flowFile = getJsonMember<const char*>("flowFile", document);

            if (!loadRoadNet(dir + roadnetFile)) {
                std::cerr << "loading roadnet file error!" << std::endl;
                return false;
            }

            if (!loadFlow(dir + flowFile)) {
                std::cerr << "loading flow file error!" << std::endl;
                return false;
            }

            if (warnings) checkWarning();
            saveReplayInConfig = saveReplay = getJsonMember<bool>("saveReplay", document);

            if (saveReplay) {
                std::string roadnetLogFile = getJsonMember<const char*>("roadnetLogFile", document);
                std::string replayLogFile = getJsonMember<const char*>("replayLogFile", document);
                setLogFile(dir + roadnetLogFile, dir + replayLogFile);
            }
        } catch (const JsonFormatError &e) {
            std::cerr << e.what() << std::endl;
            return false;
        }
        stepLog = "";
        return true;
    }

    bool Engine::loadRoadNet(const std::string &jsonFile) {
        bool ans = roadnet.loadFromJson(jsonFile);
        int cnt = 0;
        for (Road &road : roadnet.getRoads()) {
            threadRoadPool[cnt].push_back(&road);
            cnt = (cnt + 1) % threadNum;
        }
        for (Intersection &intersection : roadnet.getIntersections()) {
            threadIntersectionPool[cnt].push_back(&intersection);
            cnt = (cnt + 1) % threadNum;
        }
        for (Drivable *drivable : roadnet.getDrivables()) {
            threadDrivablePool[cnt].push_back(drivable);
            cnt = (cnt + 1) % threadNum;
        }
        jsonRoot.SetObject();
        jsonRoot.AddMember("static", roadnet.convertToJson(jsonRoot.GetAllocator()), jsonRoot.GetAllocator());
        return ans;
    }

    bool Engine::loadFlow(const std::string &jsonFilename) {
        rapidjson::Document root;
        if (!readJsonFromFile(jsonFilename, root)) {
            std::cerr << "cannot open flow file!" << std::endl;
            return false;
        }
        std::list<std::string> path;
        try {
            if (!root.IsArray())
                throw JsonTypeError("flow file", "array");
            for (rapidjson::SizeType i = 0; i < root.Size(); i++) {
                path.emplace_back("flow[" + std::to_string(i) + "]");
                rapidjson::Value &flow = root[i];
                std::vector<Road *> roads;
                const auto &routes = getJsonMemberArray("route", flow);
                roads.reserve(routes.Size());
                for (auto &route: routes.GetArray()) {
                    path.emplace_back("route[" + std::to_string(roads.size()) + "]");
                    if (!route.IsString())
                        throw JsonTypeError("route", "string");
                    std::string roadName = route.GetString();
                    auto road = roadnet.getRoadById(roadName);
                    if (!road)
                        throw JsonFormatError("No such road: " + roadName);
                    roads.push_back(road);
                    path.pop_back();
                }
                auto route = std::make_shared<const Route>(roads);

                VehicleInfo vehicleInfo;
                const auto &vehicle = getJsonMemberObject("vehicle", flow);
                vehicleInfo.len = getJsonMember<double>("length", vehicle);
                vehicleInfo.width = getJsonMember<double>("width", vehicle);
                vehicleInfo.maxPosAcc = getJsonMember<double>("maxPosAcc", vehicle);
                vehicleInfo.maxNegAcc = getJsonMember<double>("maxNegAcc", vehicle);
                vehicleInfo.usualPosAcc = getJsonMember<double>("usualPosAcc", vehicle);
                vehicleInfo.usualNegAcc = getJsonMember<double>("usualNegAcc", vehicle);
                vehicleInfo.minGap = getJsonMember<double>("minGap", vehicle);
                vehicleInfo.maxSpeed = getJsonMember<double>("maxSpeed", vehicle);
                vehicleInfo.headwayTime = getJsonMember<double>("headwayTime", vehicle);
                vehicleInfo.route = route;
                int startTime = getJsonMember<int>("startTime", flow, 0);
                int endTime = getJsonMember<int>("endTime", flow, -1);
                Flow newFlow(vehicleInfo, getJsonMember<double>("interval", flow), this, startTime, endTime,
                             "flow_" + std::to_string(i));
                flows.push_back(newFlow);
                path.pop_back();
            }
            assert(path.empty());
        } catch (const JsonFormatError &e) {
            std::cerr << "Error occurred when reading flow file" << std::endl;
            for (const auto &node : path) {
                std::cerr << "/" << node;
            }
            std::cerr << " " << e.what() << std::endl;
            return false;
        }
        return true;
    }





    void Engine::nextStep() {
        for (auto &flow : flows)
            flow.nextStep(interval);
        planRoute();
        handleWaiting();
        // пока без LaneChange?
        
        /*if (laneChange) {
            initSegments();
            planLaneChange();
            updateLeaderAndGap();
        }*/ 
        
        // notifyCross();

        getAction();
        updateLocation();
        updateAction();
        updateLeaderAndGap();

        /*if (!rlTrafficLight) {
            std::vector<Intersection> &intersections = roadnet.getIntersections();
            for (auto &intersection : intersections)
                intersection.getTrafficLight().passTime(interval);
        }*/

        if (saveReplay) {
            updateLog();
        }

        step += 1;
    }

}
