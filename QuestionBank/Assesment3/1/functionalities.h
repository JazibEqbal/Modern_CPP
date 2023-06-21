#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H
#include "Car.h"
#include "CarType.h"
#include "Vehicle.h"
#include "VehicleType.h"
#include "Insurance.h"
#include "InsuranceType.h"
#include<iostream>
#include<optional>
#include<memory>
#include<functional>
#include<algorithm>
#include<numeric>
#include<list>
#include<vector>
#include<thread>
#include<mutex>

using CarPointer = std::shared_ptr<Car>; //shared pointer of Car Type
using container  = std::list<CarPointer>; // list of Car Pointers

extern std::function<std::optional<std::list<CarPointer>>(container &data, float threshold) > AboveThreshold;

extern std::function<std::optional<std::list<float>>(container &data,VEHICLE_TYPE type) > accumulatePriceOfMatchedVehicleType;

extern std::function<std::optional<std::list<std::string>>(std::future<container&> &data)> matchingCarColour;

extern std::function<std::optional<float>(container &data) > averageInsuranceAmount;

#endif // FUNCTIONALITIES_H
