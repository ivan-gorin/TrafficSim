#include <driver.h>
#include <iostream>
#include <string>
namespace CityFlow {
    Driver::Driver(const std::string & s) {
           type = s;
           if (type == "crazy") {
               MyInfo.speedN = 0.75;
               MyInfo.posAcN = 0.75;
               MyInfo.negAcN = 0.75;
               MyInfo.minGapN = 1;
               MyInfo.turnSpeedN = 0.75;
               MyInfo.maxSpeedN = 1;
               MyInfo.usualNegAcN = 0.75;
               MyInfo.usualPosAcN = 0.75;
           } else if (type == "normal") {
               MyInfo.speedN = 0.75;
               MyInfo.posAcN = 0.75;
               MyInfo.negAcN = 0.75;
               MyInfo.minGapN = 1;
               MyInfo.turnSpeedN = 0.75;
               MyInfo.maxSpeedN = 1;
               MyInfo.usualNegAcN = 0.75;
               MyInfo.usualPosAcN = 0.75;
           } else if (type == "slow") {
               MyInfo.speedN = 0.5;
               MyInfo.posAcN = 0.5;
               MyInfo.negAcN = 0.5;
               MyInfo.minGapN = 2;
               MyInfo.turnSpeedN = 0.5;
               MyInfo.maxSpeedN = 0.75;
               MyInfo.usualNegAcN = 0.5;
               MyInfo.usualPosAcN = 0.5;
           }
       }
}
