#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H
#include "Automobile.h"
#include "CarCategory.h"
#include<iostream>
#include<unordered_map>
#include<functional>
#include<algorithm>
#include<variant>
#include<optional>
#include<list>
#include<memory>
#include<numeric>
#include<vector>
#include<future>

using listConatiner = std::list<std::unique_ptr<Automobile>>;
using conatiner = std::unordered_map<std::string, listConatiner>;

extern std::function<void(conatiner &data) > createObjects;

extern std::function<void(conatiner &obj) > averagePrice;

extern std::function<void(conatiner &data,std::list<std::string> locations) > avgLocationCarPrice;

extern std::optional<std::function<void(conatiner &data) >> listABoveThreshold;

extern std::function<std::string(conatiner &obj,std::variant<int,std::string> number) > findCarModel;

#endif // FUNCTIONALITIES_H
