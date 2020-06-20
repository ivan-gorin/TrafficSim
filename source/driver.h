#ifndef TRAFFICSIM_DRIVER
#define TRAFFICSIM_DRIVER

#include <vector>
#include <iostream>
#include <string>
namespace CityFlow {
    struct DriverProbability {
        int normal = 800; // 0 - 800
        int crazy = 950; // 800 - 950
        int slow = 1000; //950 - 1000
    };

    struct ChangeVehicleInfo {
        double speedN = 1;
        double maxPosAcN = 1;
        double maxNegAcN = 1;
        double maxSpeedN = 1;
        double usualPosAcN = 1;
        double usualNegAcN = 1;
        double turnSpeedN = 1;
        double minGapN = 1;
    };

    class Driver {
    private:
        ChangeVehicleInfo MyInfo;
        std::string type;
    public:
        Driver(const std::string & s);
        ChangeVehicleInfo getInfo();
        void changeType( std::string &s);
    };

}

#endif
