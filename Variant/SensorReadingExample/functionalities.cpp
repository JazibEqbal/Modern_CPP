#include "functionalities.h"
#include "SensorReading.h"
#include <iostream>
#include <functional>
#include <numeric>
#include <limits>
#include <variant>
#include <memory>
#include <list>
#include "ReadingType.h"

using myVariant = std::variant<int, std::string>;
using myPointer = std::list<std::unique_ptr<SensorReading>>;

std::function<myVariant(myPointer &)> findSensorIdWithHighestReading =
    [](myPointer &readings)
{
    if (readings.empty())
    {
        return myVariant{};
    }
    myVariant maxSensorId;
    float maxValue = readings.front()->getReadingValue();

    for (auto &it : readings)
    {
        std::visit([&](const auto &sensorId, float value)
                   {
                if (value > maxValue) {
                    maxValue = value;
                    maxSensorId = sensorId;
                } },
                   it->getSensorId(), it->getReadingValue());
    };

    return maxSensorId;
};

// Lambda function to find the average sensor reading value for the given sensor IDs
std::function<float(myPointer &obj, std::list<myVariant> &id)> findAverageSensorReadingValue =
    [](const myPointer &readings, const std::list<myVariant> &sensorIds)
{
    if (readings.empty() || sensorIds.empty())
    {
        return 0.0f;
    }
    int count = 0;
    float totalValue = 0.0f;

    for (auto &it : readings)
    {
        std::visit([&](const auto &sensorId, float value)
                   {
                if (std::find(sensorIds.begin(), sensorIds.end(), sensorId) != sensorIds.end()) {
                    totalValue += value;
                    count++;
                } },
                   it->getSensorId(), it->getReadingValue());
    }
    return (count > 0) ? (totalValue / count) : 0.0f;
};

// Lambda function to find the reading status for one sensor whose ID is passed as a parameter
std::function<READING_TYPE(myPointer &obj, myVariant)> findSenorId =
    [](myPointer &obj, myVariant sensorid)
{
    READING_TYPE status = READING_TYPE::DEFAULT;

    for (auto &it : obj)
    {
        std::visit([&](myVariant &id)
                   {
                if (sensorid == id){
                    status = it->getType();
                } },
                   it->getSensorId());
    }
    return status;
};

std::function<myPointer(const myPointer &, float)> findReadingsAboveThreshold =
    [](const std::list<std::unique_ptr<SensorReading>> &readings, float threshold)
{
    myPointer result;

    for (const auto &reading : readings)
    {
        std::visit([&](const auto &value)
                   {
                if (value > threshold) {
                    result.emplace_back(std::make_unique<SensorReading>(*reading));
                } },
                   reading->getReadingValue());
    }
    return result;
};

// Lambda function to find the first N sensors from the Data container
std::function<myPointer(const myPointer &, int)> findFirstNSensors =
    [](const myPointer &readings, int N)
{
    int count = 0;
    myPointer result;

    auto it = readings.begin();
    for (int i = 0; i < count; i++)
    {
        std::visit([&result](const auto &data)
                   { result.emplace_back(std::make_unique<SensorReading>(data)); },
                   (*it)->getSensorId());
        it++;
    }
    return result;
};
