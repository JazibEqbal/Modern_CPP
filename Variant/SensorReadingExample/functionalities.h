#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H
#include "SensorReading.h"
#include<iostream>
#include<functional>
#include<numeric>
#include<limits>
#include <variant>

extern std::function<std::variant<int,std::string>(const std::vector<SensorReading>& readings)> findSensorIdWithHighestReading;

std::variant<int, std::string> hh(const std::vector<SensorReading> &readings);

#endif // FUNCTIONALITIES_H
