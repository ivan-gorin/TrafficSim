#include <string>
#include <iostream>
#include <weather.h>

namespace CityFlow {
    Weather::Weather(const std::string &s) {
        type = s;
        intensity = 1;
        if (type == "sun") {
            MyInfo.maxPosAcN = 1;
            MyInfo.maxNegAcN = 1;
            MyInfo.minGapN = 1;
            MyInfo.turnSpeedN = 1;
            MyInfo.maxSpeedN = 1;
            MyInfo.usualNegAcN = 1;
            MyInfo.usualPosAcN = 1;
        } else if (type == "fog") {
            MyInfo.maxPosAcN = 0.9;
            MyInfo.maxNegAcN = 0.9;
            MyInfo.minGapN = 2;
            MyInfo.turnSpeedN = 0.9;
            MyInfo.maxSpeedN = 0.8;
            MyInfo.usualNegAcN = 0.9;
            MyInfo.usualPosAcN = 0.9;
        } else if (type == "rain") {
            MyInfo.maxPosAcN = 0.8;
            MyInfo.maxNegAcN = 0.8;
            MyInfo.minGapN = 2.5;
            MyInfo.turnSpeedN = 0.5;
            MyInfo.maxSpeedN = 0.83;
            MyInfo.usualNegAcN = 0.8;
            MyInfo.usualPosAcN = 0.8;
        } else if (type == "snow") {
            MyInfo.maxPosAcN = 0.4;
            MyInfo.maxNegAcN = 0.4;
            MyInfo.minGapN = 3;
            MyInfo.turnSpeedN = 0.6;
            MyInfo.maxSpeedN = 0.36;
            MyInfo.usualNegAcN = 0.4;
            MyInfo.usualPosAcN = 0.4;
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
            MyInfo.maxPosAcN = 1;
            MyInfo.maxNegAcN = 1;
            MyInfo.minGapN = 1;
            MyInfo.turnSpeedN = 1;
            MyInfo.maxSpeedN = 1;
            MyInfo.usualNegAcN = 1;
            MyInfo.usualPosAcN = 1;
        } else if (type == "fog") {
            MyInfo.maxPosAcN = 0.9;
            MyInfo.maxNegAcN = 0.9;
            MyInfo.minGapN = 2;
            MyInfo.turnSpeedN = 0.9;
            MyInfo.maxSpeedN = 0.8;
            MyInfo.usualNegAcN = 0.9;
            MyInfo.usualPosAcN = 0.9;
        } else if (type == "rain") {
            MyInfo.maxPosAcN = 0.8;
            MyInfo.maxNegAcN = 0.8;
            MyInfo.minGapN = 2.5;
            MyInfo.turnSpeedN = 0.5;
            MyInfo.maxSpeedN = 0.83;
            MyInfo.usualNegAcN = 0.8;
            MyInfo.usualPosAcN = 0.8;
        } else if (type == "snow") {
            MyInfo.maxPosAcN = 0.4;
            MyInfo.maxNegAcN = 0.4;
            MyInfo.minGapN = 3;
            MyInfo.turnSpeedN = 0.6;
            MyInfo.maxSpeedN = 0.36;
            MyInfo.usualNegAcN = 0.4;
            MyInfo.usualPosAcN = 0.4;
        }
    }

    const std::string &Weather::getType()
    {
        return type;
    }
    void Weather::changeIntensity(double newIntensity) {
        intensity = newIntensity;
    }
    double Weather::GetIntensity() {
        return intensity;
    }
    
};
