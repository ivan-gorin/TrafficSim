#include <iostream>
#include <string>

namespace traffic_model {
    class Lane;
    class Route;
    class Engine;

    struct VehicleInfo {
        double length;
        double width;
        double speed;
        int type;
        int lane;
        double maxPosAcc;
        double maxNegAcc;
        double maxSpeed;
        int minGap;
    };

    class Vehicle {
    private:
        VehicleInfo vehicleinfo;
        std::string id;
        Engine *engine;
    public:
        Vehicle(const VehicleInfo &init, const std::string &id, Engine *engine);
        Vehicle(const Vehicle &vehicle);
    };
}
