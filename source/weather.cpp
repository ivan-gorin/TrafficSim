#include <string>
#include <iostream>
#include <weather.h>

namespace CityFlow {
    Weather::Weather(const std::string &s) {
        type = s;
        if (type == "sun") {
            MyInfo.maxPosAcN = 1;
            MyInfo.maxNegAcN = 1;
            MyInfo.minGapN = 1;
            MyInfo.turnSpeedN = 1;
            MyInfo.maxSpeedN = 1;
            MyInfo.usualNegAcN = 1;
            MyInfo.usualPosAcN = 1;
        } else if (type == "fog") {
            MyInfo.maxPosAcN = 0.75;
            MyInfo.maxNegAcN = 0.75;
            MyInfo.minGapN = 1;
            MyInfo.turnSpeedN = 0.75;
            MyInfo.maxSpeedN = 1;
            MyInfo.usualNegAcN = 0.75;
            MyInfo.usualPosAcN = 0.75;
        } else if (type == "rain") {
            MyInfo.maxPosAcN = 0.2;
            MyInfo.maxNegAcN = 0.2;
            MyInfo.minGapN = 3;
            MyInfo.turnSpeedN = 0.5;
            MyInfo.maxSpeedN = 0.5;
            MyInfo.usualNegAcN = 0.2;
            MyInfo.usualPosAcN = 0.2;
        }
    }

    ChangeVehicleInfo Weather::getInfo()
    {
        return MyInfo;
    }

    void Weather::changeType(const std::string &s)
    {
        type = s;
        if (type == "sun") {
            MyInfo.speedN = 0.75;
            MyInfo.maxPosAcN = 0.75;
            MyInfo.maxNegAcN = 0.75;
            MyInfo.minGapN = 1;
            MyInfo.turnSpeedN = 0.75;
            MyInfo.maxSpeedN = 1;
            MyInfo.usualNegAcN = 0.75;
            MyInfo.usualPosAcN = 0.75;
        } else if (type == "fog") {
            MyInfo.speedN = 0.75;
            MyInfo.maxPosAcN = 0.75;
            MyInfo.maxNegAcN = 0.75;
            MyInfo.minGapN = 1;
            MyInfo.turnSpeedN = 0.75;
            MyInfo.maxSpeedN = 1;
            MyInfo.usualNegAcN = 0.75;
            MyInfo.usualPosAcN = 0.75;
        } else if (type == "rain") {
            MyInfo.speedN = 0.5;
            MyInfo.maxPosAcN = 0.5;
            MyInfo.maxNegAcN = 0.5;
            MyInfo.minGapN = 2;
            MyInfo.turnSpeedN = 0.5;
            MyInfo.maxSpeedN = 0.75;
            MyInfo.usualNegAcN = 0.5;
            MyInfo.usualPosAcN = 0.5;
        }
    }
    
};
