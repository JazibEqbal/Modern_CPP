#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include "Vehicle.h"
#include "Car.h"
#include<iostream>
#include "VehicleType.h"
#include<list>
#include<iostream>

float averageVehicleType(std::list<Vehicle*> &obj);

void findGivenVehicleType(std::list<Vehicle*> &obj, enum class VehicleType type);

#endif // FUNCTIONALITIES_H
