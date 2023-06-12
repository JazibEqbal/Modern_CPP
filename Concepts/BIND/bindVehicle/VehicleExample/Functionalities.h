#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include "Vehicle.h"
#include "Car.h"
#include <iostream>
#include "VehicleType.h"
#include <list>
#include <iostream>
#include <algorithm>

extern std::function<float(const std::list<Vehicle *> &vehicles)> averageVehicleType;

void findGivenVehicleType(const std::list<Vehicle *> &vehicles, VehicleType type);

extern std::function<int(const std::list<Vehicle *> &vehicles, const std::list<VehicleType> &types)> countOfGivenTypes;

#endif // FUNCTIONALITIES_H
