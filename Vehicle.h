#include <iostream>
#include <string>
#include "Engine.h"


namespace CityFlow 
    class Lane;
    class Route;
    class Engine;

    struct VehicleInfo {
        int length;
        int width;
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
        Engine *engine;
    public:
        Vehicle(const VehicleInfo &init, const std::string &id, Engine *engine);
        Vehicle(const Vehicle &vehicle);
    };
}
