#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H
#include "Insurance.h"
#include "Vehicle.h"
#include "Car.h"
#include "Insurancetype.h"
#include "VehicleType.h"
#include "Car.h"
#include<iostream>
#include<optional>
#include<memory>
#include<functional>
#include<algorithm>
#include<numeric>
#include<list>
#include<vector>

using CarPointer = std::shared_ptr<Car>; //shared pointer of Car Type
using container  = std::list<CarPointer>; // list of Car Pointers

using myVariant = std::variant<int,std::string>; //variant of type it or string

//function to check matching car type from argument passed
extern std::function<void(container&, CAR_TYPE) > checkMatchingCarType;

//function to find id of min and max element on the basis of insurance amount
extern std::function<void(container&) > vechicleIDMinMax;

//function to find count of count of matching vehicle type and reg year
extern std::function<int(container&, VEHICLE_TYPE, int) > countOfCarForMatchingTypeAndYear;

//function to find all instance of cars which satisfies the passed given conditions
extern std::function<std::optional<container>(container&, VEHICLE_TYPE, std::string) > instanceOfCars;

//find to display list of car unit tax price for all car instances
extern std::function<std::optional<std::list<float>>(container &) > carUnitTaxPrice;

//function to find first matching id
extern std::function<myVariant(container&, myVariant) > firstMatchingInstance;

//function to find average of all car instances
extern std::function<float(container&)> calculateAverageOfAllCarInstances;

//function to find list of cars above threshold
extern std::function<std::optional<std::list<CarPointer>>(container &, float)> carTypeAboveThreshold;

#endif // FUNCTIONALITIES_H
