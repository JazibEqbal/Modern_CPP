#include "SensorReading.h"
using vType = std::variant<int, std::string>;

SensorReading::SensorReading(const vType &sensorId, const vType &readingId, READING_TYPE type, float readingValue)
    : sensorId(sensorId), readingId(readingId), type(type), readingValue(readingValue) {}

SensorReading::~SensorReading()
{
    std::cout << "Des\n";
}
std::string displayType(enum class READING_TYPE type)
{
    if (type == READING_TYPE::ACCEPTABLE)
    {
        return "ACCEPTABLE";
    }
    else if (type == READING_TYPE::DEFAULT)
    {
        return "DEFAULT";
    }
    else
    {
        return "ERROR";
    }
}

std::ostream& operator<<(std::ostream& os, const SensorReading& rhs)
{
    os << "sensorId: ";
    std::visit([&](const auto& arg) { os << arg; }, rhs.sensorId);
    os << " readingId: ";
    std::visit([&](const auto& arg) { os << arg; }, rhs.readingId);
    os << " readingType: " << displayType(rhs.type)
       << " readingValue: " << rhs.readingValue;
    return os;
}


