#include <iostream>
#include "SensorReading.h"
#include "ReadingType.h"
#include <variant>
#include <array>
#include <list>
#include <memory>
#include <algorithm>
#include "functionalities.h"

using myVariant = std::variant<int, std::string>;
using myPointer = std::list<std::unique_ptr<SensorReading>>;

int main()
{
    myPointer readings;
    readings.emplace_back(std::make_unique<SensorReading>(123, "A1", READING_TYPE::ACCEPTABLE, 5.67));
    readings.emplace_back(std::make_unique<SensorReading>("abc", "B", READING_TYPE::DEFAULT, 8.99));
    readings.emplace_back(std::make_unique<SensorReading>(56, "C", READING_TYPE::ACCEPTABLE, 5.14));
    readings.emplace_back(std::make_unique<SensorReading>("jj", "C", READING_TYPE::ERROR, 9.14));
    readings.emplace_back(std::make_unique<SensorReading>(6, "D4", READING_TYPE::ERROR, 32.14));

    myVariant maxsensorId = findSensorIdWithHighestReading(readings);

    //std::visit([](auto &arg){std::cout<<arg;},maxsensorId);

    std::list<myVariant> sensorIds = {123, "abc", 6};
    float averageValue = findAverageSensorReadingValue(readings, sensorIds);
    //std::cout << "Average sensor reading value for specified IDs: " << averageValue << std::endl;

    myVariant sensorId = 6;
    //std::cout<<displayType(findSenorId(readings, sensorId))<<"\n";
    
    auto aboveThresholdReadings = findReadingsAboveThreshold(readings, 2.5f);
    // if(aboveThresholdReadings.has_value()){
    //     for(auto &it: aboveThresholdReadings.value()){
    //         std::cout<<(*it);
    //     }
    // }
    // std::list<std::unique_ptr<SensorReading>> firstNSensors = findFirstNSensors(readings, 3);
    // for (const auto &it : firstNSensors)
    // {
    //     std::cout << "sensorId: " << std::visit([](auto arg)
    //                                             { return arg; },
    //                                             it->getSensorId());
    //     std::cout << " value: " << std::visit([](auto arg)
    //                                           { return arg; },
    //                                           it->getReadingValue());
    // }
}

    // if (std::holds_alternative<int>(maxsensorId))
    // {
    //     std::cout << "Sensor ID with the  reading value: " << std::get<int>(maxsensorId) << std::endl;
    // }
    // else if (std::holds_alternative<std::string>(maxsensorId))
    // {
    //     std::cout << "Sensor ID with the highest reading value: " << std::get<std::string>(maxsensorId) << std::endl;
    // }
    // else
    // {
    //     std::cout << "No sensor ID found with the highest reading value" << std::endl;
    // }