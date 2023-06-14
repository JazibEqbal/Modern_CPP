#include "SensorReading.h"
SensorReading::SensorReading(const std::variant<int, std::string> &sensorId, const std::variant<int, std::string> &readingId, READING_TYPE type, float readingValue)
: sensorId(sensorId), readingId(readingId), type(type), readingValue(readingValue) {}

SensorReading::~SensorReading()
{
    std::cout<<"Des\n";
}

std::ostream &operator<<(std::ostream &os, const SensorReading &rhs) {
    os << "sensorId: "<< std::visit([](auto arg){return arg;}, rhs.sensorId)
       << " readingId: " << std::visit([](auto arg){return arg;}, rhs.readingId)
       << " readingType: " <<displayType(rhs.type)
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


