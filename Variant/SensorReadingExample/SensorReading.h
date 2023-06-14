#ifndef SENSORREADING_H
#define SENSORREADING_H
#include <iostream>
#include <string>
#include <variant>
#include <vector>
#include <algorithm>
#include "ReadingType.h"

class SensorReading {
private:
    std::variant<int, std::string> sensorId;
    std::variant<int, std::string> readingId;
    READING_TYPE type;
    float readingValue;

public:
    SensorReading() = default;
    SensorReading(const SensorReading& other) = default;
    SensorReading(const std::variant<int, std::string>& sensorId, const std::variant<int, std::string>& readingId, READING_TYPE type, float readingValue);
    SensorReading(SensorReading&& other) noexcept
        : sensorId(std::move(other.sensorId)), readingId(std::move(other.readingId)), type(other.type), readingValue(other.readingValue) {}

    std::variant<int, std::string> getSensorId() const { return sensorId; }
    void setSensorId(const std::variant<int, std::string> &sensorId_) { sensorId = sensorId_; }

    std::variant<int, std::string> getReadingId() const { return readingId; }
    void setReadingId(const std::variant<int, std::string> &readingId_) { readingId = readingId_; }

    READING_TYPE getType() const { return type; }
    void setType(const READING_TYPE &type_) { type = type_; }

    float getReadingValue() const { return readingValue; }
    void setReadingValue(float readingValue_) { readingValue = readingValue_; }

    friend std::ostream &operator<<(std::ostream &os, const SensorReading &rhs);
    
};

#endif // SENSORREADING_H
