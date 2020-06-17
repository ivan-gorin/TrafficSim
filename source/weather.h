#ifndef TRAFFICSIM_WEATHER
#define TRAFFICSIM_WEATHER

#include "driver.h"

#include <vector>
#include <iostream>
#include <string>

namespace CityFlow {

    class Weather {
    private:
        ChangeVehicleInfo MyInfo;
        std::string type;
    public:
        Weather(const std::string &s);
        ChangeVehicleInfo getInfo();
        void changeType(const std::string &s);
    };

}

#endif
