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
    readings.emplace_back(std::make_unique<SensorReading>(56, "C", READING_TYPE::ERROR, 5.14));
    readings.emplace_back(std::make_unique<SensorReading>(4156, "C", READING_TYPE::ACCEPTABLE, 9.14));
    readings.emplace_back(std::make_unique<SensorReading>(6, "D4", READING_TYPE::ERROR, 3.14));

    myVariant maxsensorId = findSensorIdWithHighestReading(readings);

    if (std::holds_alternative<int>(maxsensorId))
    {
        std::cout << "Sensor ID with the highest reading value: " << std::get<int>(maxsensorId) << std::endl;
    }
    else if (std::holds_alternative<std::string>(maxsensorId))
    {
        std::cout << "Sensor ID with the highest reading value: " << std::get<std::string>(maxsensorId) << std::endl;
    }
    else
    {
        std::cout << "No sensor ID found with the highest reading value" << std::endl;
    }

    std::list<myVariant> sensorIds = {"A1", "B2", "C3"};
    float averageValue = findAverageSensorReadingValue(readings, sensorIds);
    std::cout << "Average sensor reading value for specified IDs: " << averageValue << std::endl;

    myVariant sensorId = "D4";
    READING_TYPE status = findSenorId(readings, sensorId);
    std::cout << "Reading status for sensor ID " << static_cast<int>(status) << std::endl;

    myPointer aboveThresholdReadings = findReadingsAboveThreshold(readings, 2.5f);
    for (auto &it : aboveThresholdReadings)
    {
        std::cout << "sensorId: " << std::visit([](auto arg)
                                                { return arg; },
                                                it->getSensorId());
        std::cout << " readingId: " << std::visit([](auto arg)
                                                  { return arg; },
                                                  it->getReadingId());
    }

    std::list<std::unique_ptr<SensorReading>> firstNSensors = findFirstNSensors(readings, 3);
    for (const auto &it : firstNSensors)
    {
        std::cout << "sensorId: " << std::visit([](auto arg)
                                                { return arg; },
                                                it->getSensorId());
        std::cout << " value: " << std::visit([](auto arg)
                                              { return arg; },
                                              it->getReadingValue());
    }
}
