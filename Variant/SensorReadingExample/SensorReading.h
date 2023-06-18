#ifndef SENSORREADING_H
#define SENSORREADING_H
#include <iostream>
#include <string>
#include <variant>
#include <vector>
#include <algorithm>
#include "ReadingType.h"

using vType = std::variant<int, std::string>;

class SensorReading {
private:
    vType sensorId;
    vType readingId;
    READING_TYPE type;
    float readingValue;
public:
    SensorReading() = default;
    SensorReading(const SensorReading& other) = delete;
    SensorReading(vType& sensorId, vType& readingId, READING_TYPE type, float readingValue);
    SensorReading(SensorReading&& other)
        : sensorId(std::move(other.sensorId)), readingId(std::move(other.readingId)), type(other.type), readingValue(other.readingValue) {}
    ~SensorReading();
    vType getSensorId() const { return sensorId; }
    void setSensorId(const vType &sensorId_) { sensorId = sensorId_; }

    vType getReadingId() const { return readingId; }
    void setReadingId(const vType &readingId_) { readingId = readingId_; }

    READING_TYPE getType() const { return type; }
    void setType(const READING_TYPE &type_) { type = type_; }

    float getReadingValue() const { return readingValue; }
    void setReadingValue(float readingValue_) { readingValue = readingValue_; }

    friend std::ostream &operator<<(std::ostream &os, const SensorReading &rhs);
    
};
std::string displayType(enum class READING_TYPE type);

#endif // SENSORREADING_H
