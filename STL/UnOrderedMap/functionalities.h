#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include <functional>
#include "AutoMobile.h"
#include "CarCategory.h"
#include <algorithm>
#include <iostream>
#include <list>
#include <numeric>
#include <unordered_map>
#include <future>

using Variant = std::variant<std::string,int>;

using myPointer = std::unique_ptr<AutoMobile>;

using CarPriceList=std::list<std::unique_ptr<AutoMobile>>;

using container=std::unordered_map<std::string,CarPriceList>;

extern std::function<void(container&)> CreateAutomobileObjects;

extern std::function<void(container&)> FindAverageCarPrice;

extern std::function<void(container&, std::list<std::string>&) > FindAverageCarPriceOfAllUnits;

extern std::function<void(container&, std::future<Variant> &) > FindCarModelusingSerialNumber;

extern std::function<void(container&) > FindGreaterThanCarPrice;

#endif // FUNCTIONALITIES_H
