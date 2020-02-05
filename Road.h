#include <vector>
#include <list>
#include <string>
#include <map>

namespace CityFlow {
    class Vehicle;
    class Lane;
    class Road;
    class Intersection;
    class Network;
    class Point {
    public:
        double x = 0.0;
        double y = 0.0;
        Point() = default;
        Point(double x, double y);
    };
    
    class Lane {
    private:
        int laneIndex;
        double maxSpeed;
        std::list<Vehicle*> vehicles;
        Road* parentRoad = nullptr;
    
    public:
        Lane();
        Lane(double maxSpeed, int laneIndex, Road* parentRoad);
    };
    
    class Road {
    private:
        std::string id;
        Intersection* startInt = nullptr;
        Intersection* endInt = nullptr;
        std::vector<Lane> lanes;
        std::vector<Point> points;
    
    public:
        std::string getId() const {
            return id;
        }
        
        const Intersection &getStartIntersection() const {
            return *(this->startInt);
        }

        const Intersection &getEndIntersection() const {
            return *(this->endInt);
        }
    };

    class Intersection {
    private:
        std::string id;
        Point point;
        std::vector<Road *> roads;

    public:
        std::string getId() const {
            return this->id;
        }

        const std::vector<Road *> &getRoads() const {
            return this->roads;
        }

        std::vector<Point> getOutline();
    };

    class RoadNet {
    private:
        std::vector<Road> roads;
        std::vector<Intersection> intersections;
        std::map<std::string, Road *> roadMap;
        std::map<std::string, Intersection *> interMap;
        std::vector<Lane *> lanes;

    public:
        const std::vector<Road> &getRoads() const { return this->roads; }

        std::vector<Road> &getRoads() { return this->roads; }

        const std::vector<Intersection> &getIntersections() const { return this->intersections; }

        std::vector<Intersection> &getIntersections() { return this->intersections; }

        Road *getRoadById(const std::string &id) const {
            return roadMap.count(id) > 0 ? roadMap.at(id) : nullptr;
        }

        Intersection *getIntersectionById(const std::string &id) const {
            return interMap.count(id) > 0 ? interMap.at(id) : nullptr;
        }

        const std::vector<Lane *> &getLanes() const {
            return lanes;
        }

        void reset();
    };

}