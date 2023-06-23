#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include "CarUnit.h"
#include "CarUnitType.h"
#include<iostream>
#include<optional>
#include<functional>
#include<algorithm>
#include<vector>
#include<memory>
#include<thread>
#include<future>
#include<list>
#include<thread>

using mypointer = std::shared_ptr<CarUnit>;
using container  = std::vector<mypointer>;

extern std::function<std::optional<std::list<float>>(container &) > carUnitPrice;

extern std::function<void(container &, std::future<std::string>& ) > matchingCarUnitType;

extern std::function<void(container &, std::future<float> &)> capacityAboveThreshold;

extern std::function<int(mypointer &) > registrationCost;

extern std::function<void(std::future<float> &,container &) >  allMatchingInstanceOfCar;

#endif // FUNCTIONALITIES_H
