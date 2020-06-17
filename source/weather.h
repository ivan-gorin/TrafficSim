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

    class Weather {
    private:
        ChangeVehicleInfo MyInfo;
        std::string type;
    public:
        Weather(const std::string &s);
    };

}
