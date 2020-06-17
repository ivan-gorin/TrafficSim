#ifndef TRAFFICSIM_DRIVER
#define TRAFFICSIM_DRIVER

#include <vector>
#include <iostream>
#include <string>
namespace CityFlow {
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
    };

}

#endif
