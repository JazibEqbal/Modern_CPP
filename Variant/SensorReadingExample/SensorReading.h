#ifndef SENSORREADING_H
#define SENSORREADING_H
#include<iostream>
#include<variant>
#include "Readings.h"

using Type = std::variant<int,std::string>;

class SensorReading
{
private:
    Type sensorId;
    Type readingId;
    enum class READING_TYPE readingType;
    float readingValue;
public:
    SensorReading() = default;
    SensorReading(const SensorReading &obj) = default;
    SensorReading(Type,Type,enum class READING_TYPE type,float value);
    //SensorReading(SensorReading &&obj) = default;
    ~SensorReading();

    enum class READING_TYPE getType() const {return readingType;};

    float getReadingValue() const { return readingValue; }
    void setReadingValue(float readingValue_) { readingValue = readingValue_; }

    Type getSensorId() const { return sensorId; }
    void setSensorId(const Type &sensorId_) { sensorId = sensorId_; }

    Type getReadingId() const { return readingId; }
    void setReadingId(const Type &readingId_) { readingId = readingId_; }

    friend std::ostream &operator<<(std::ostream &os, const SensorReading &rhs);

};

std::string displayType(enum class READING_TYPE Type);

#endif // SENSORREADING_H
