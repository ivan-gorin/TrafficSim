#include <string>
#include <iostream>
#include <weather.h>

namespace CityFlow {
    Weather::Weather(std::string &s) {
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
        } else if (type == "frog") {
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
