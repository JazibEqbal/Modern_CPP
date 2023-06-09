#include "SensorReading.h"

SensorReading::SensorReading(Type id, Type reading, READING_TYPE type, float value)
: sensorId{id}, readingId{reading}, readingType{type}, readingValue{value} {}

SensorReading::~SensorReading()
{
    std::cout<<"Des\n";
}

std::ostream &operator<<(std::ostream &os, const SensorReading &rhs) {
    os << "sensorId: "<< std::visit([](auto arg){return arg;}, rhs.sensorId)
       << " readingId: " << std::visit([](auto arg){return arg;}, rhs.readingId)
       << " readingType: " <<displayType(rhs.readingType)
       << " readingValue: " << rhs.readingValue;
    return os;
}

std::string displayType(enum class READING_TYPE type){
    if(type == READING_TYPE::ACCEPTABLE){
        return "ACCEPTABLE";
    } else if(type == READING_TYPE::DEFAULT){
        return "DEFAULT";
    }else {
        return "ERROR";
    }
}