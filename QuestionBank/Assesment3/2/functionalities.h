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

extern std::function<std::list<float>(container &data) > carUnitPrice;

extern std::function<CAR_UNIT_TYPE(container &data, std::future<std::string>& fu) > matchingCarUnitType;

extern std::function<std::vector<int>(container &data,std::future<int>& fu) > capacityAboveThreshold;

extern std::function<int(mypointer &) > registrationCost;

extern std::function<std::vector<mypointer>(int price,container &data) > allMatchingInstanceOfCar;

#endif // FUNCTIONALITIES_H
