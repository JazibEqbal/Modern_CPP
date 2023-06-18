#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H
#include "SensorReading.h"
#include <iostream>
#include <functional>
#include <numeric>
#include <limits>
#include <variant>
#include <memory>
#include <list>
#include<optional>
#include<vector>
#include "ReadingType.h"

using myVariant = std::variant<int, std::string>;
using myPointer = std::list<std::unique_ptr<SensorReading>>;

extern std::function<myVariant(myPointer &)> findSensorIdWithHighestReading;

extern std::function<float(myPointer &obj, std::list<myVariant> &id)> findAverageSensorReadingValue;

extern std::function<READING_TYPE(myPointer &obj, myVariant)> findSenorId;

extern std::function<std::optional<myPointer>(myPointer &,float)> findReadingsAboveThreshold;

extern std::function<std::optional<myPointer>(const myPointer &, int)> findFirstNSensors;

#endif // FUNCTIONALITIES_H
