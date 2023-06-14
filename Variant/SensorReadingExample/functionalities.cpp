#include "functionalities.h"

std::variant<int, std::string> hh(const std::vector<SensorReading> &readings)
{
    std::variant<int, std::string> maxSensorId;
    float maxReadingValue = readings.front().getReadingValue();

    for (const SensorReading &it : readings)
    {
        std::visit([&](auto &sensorId, float &readingValue)
                   {
            if (readingValue > maxReadingValue) {
                maxReadingValue = readingValue;
                maxSensorId = sensorId;
            } },
                   it.getSensorId(), it.getReadingValue());
    }

    return maxSensorId;
}

std::function<std::variant<int, std::string>(const std::vector<SensorReading> &readings)> findSensorIdWithHighestReading =
    [](const std::vector<SensorReading> &readings)
{
    std::variant<int, std::string> maxSensorId;
    float maxReadingValue = readings.front().getReadingValue();

    for (const SensorReading &it : readings)
    {
        std::visit([&](auto &sensorId, float &readingValue)
                   {
            if (readingValue > maxReadingValue) {
                maxReadingValue = readingValue;
                maxSensorId = sensorId;
            } },
                   it.getSensorId(), it.getReadingValue());
    }

    return maxSensorId;
};