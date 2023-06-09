#ifndef SENSORREADING_H
#define SENSORREADING_H
#include<iostream>
#include<variant>
#include "Readings.h"

using TypeSensor = std::variant<int,std::string>;
using TypeReading = std::variant<int,std::string>;

class SensorReading
{
private:
    TypeSensor sensorId;
    TypeReading readingId;
    enum class READING_TYPE readingType;
    float readingValue;
public:
    SensorReading() = default;
    SensorReading(const SensorReading &obj) = default;
    SensorReading(TypeSensor,TypeReading,enum class READING_TYPE type,float value);
    // SensorReading(SensorReading &move): sensorId{std::move(move.sensorId)}, readingId{std::move(move.readingId)}, 
    // readingType{std::move(move.readingType)},readingValue{std::move(move.readingValue)}};
    ~SensorReading();

    TypeReading getReadingId() const { return readingId; }
    void setReadingId(const TypeReading &readingId_) { readingId = readingId_; }

    enum class READING_TYPE getType() const {return readingType;};

    float getReadingValue() const { return readingValue; }
    void setReadingValue(float readingValue_) { readingValue = readingValue_; }

    TypeSensor getSensorId() const { return sensorId; }
    void setSensorId(const TypeSensor &sensorId_) { sensorId = sensorId_; }

    friend std::ostream &operator<<(std::ostream &os, const SensorReading &rhs);

};

std::string displayType(enum class READING_TYPE Type);

#endif // SENSORREADING_H
