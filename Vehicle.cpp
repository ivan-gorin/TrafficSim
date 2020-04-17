#include "Vehicle.h"
#include <iostream>

namespace traffic_model {
    Vehicle::Vehicle(const Vehicle &vehicle) : vehicleinfo(vehicle.vehicleinfo), 
        id(vehicle.id), engine(vehicle.engine) { }
    Vehicle::Vehicle(const VehicleInfo &init, const std::string &id, Engine *engine) :
        vehicleinfo(init), id(id), engine(engine) { }
}
