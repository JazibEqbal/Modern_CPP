#ifndef SENSORREADING_H
#define SENSORREADING_H

#include <variant>
#include <iostream>
#include "ReadingType.h"


std::string displayEnum(ReadingType value);

class SensorReading
{
private:
    std::variant<int,std::string> sensorId;
    std::variant<int,std::string> readingId;
    ReadingType readingType;
    float readingValue;


public:
    SensorReading() = default;
    SensorReading(const SensorReading& obj) = default;
    SensorReading(SensorReading&& obj) = default;
    SensorReading(
        std::variant<int,std::string> sensorId, std::variant<int, std::string> readingId, 
        ReadingType readingType, float readingValue
    );

    ~SensorReading() {
        std::cout << "SensorReading Instance destroyed\n";
    }

    std::variant<int,std::string> getSensorId() const { return sensorId; }
    void setSensorId(const std::variant<int,std::string> &sensorId_) { sensorId = sensorId_; }

    std::variant<int, std::string> getReadingId() const { return readingId; }
    void setReadingId(const std::variant<int, std::string> &readingId_) { readingId = readingId_; }

    ReadingType getReadingType() const { return readingType; }
    void setReadingType(const ReadingType &readingType_) { readingType = readingType_; }

    float getReadingValue() const { return readingValue; }
    void setReadingValue(float readingValue_) { readingValue = readingValue_; }

    friend std::ostream &operator<<(std::ostream &os, const SensorReading &rhs);

    
};

#endif // SENSORREADING_H
