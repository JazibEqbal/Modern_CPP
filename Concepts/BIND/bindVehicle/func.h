#ifndef FUNC_H
#define FUNC_H
#include <iostream>
#include <list>
#include <functional>
#include <algorithm>
#include "Veh.h"

extern float findAveragePrice(const std::list<Vehicle>& vehicles);

extern void findGivenVehicleType(const std::list<Vehicle>& vehicles, VEHICLE_TYPE type);

extern void countOfGivenTypes(const std::list<Vehicle>& vehicles, const std::list<VEHICLE_TYPE>& types);

#endif // FUNC_H
