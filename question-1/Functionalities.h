#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H
#include <optional>
#include <list>
#include "Car.h"
#include "Vehicle.h"
#include <functional>
#include <memory>
#include <future>

using pointer = std::shared_ptr<Car>;
using container = std::list<pointer>;

using stringcontainer = std::list<std::string>;



extern std::function<std::optional<container>(container &, float)> carsAboveThreshold;
extern std::function<std::optional<std::list<float>>(container&,VehicleType )> returnCarPriceList;
extern std::function<std::optional<std::list<std::string>>(container &)> returnCarColorContainer;
extern std::function<float(container&)> averageInsuranceAmount;

#endif // FUNCTIONALITIES_H
