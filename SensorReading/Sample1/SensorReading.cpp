#include "SensorReading.h"
#include "ReadingType.h"

std::string displayEnum(ReadingType value)
{
    if (value == ReadingType::ACCEPTABLE){
        return "ACCEPTABLE";
    }

    else if(value == ReadingType::DEFAULT){
        return "DEFAULT";
    }

    else{
        return "ERROR";
    }
}

std::ostream &operator<<(std::ostream &os, const SensorReading &rhs) {
    
    os << " SensorId: "; 

    std::visit( [&](auto arg){ os<< arg; }  , rhs.sensorId);

    os << " readingId: "; 
    std::visit( [&](auto arg){ os<< arg; }  , rhs.readingId);

    os << " readingType: " << displayEnum(rhs.readingType)
    
    << " readingValue: " << rhs.readingValue;

    return os;
}

SensorReading::SensorReading(std::variant<int, std::string> sensorId, std::variant<int,std::string> readingId, 
    ReadingType readingType, float readingValue)
        : sensorId(sensorId), readingId(readingId), readingType(readingType), readingValue(readingValue)

{
    
}
