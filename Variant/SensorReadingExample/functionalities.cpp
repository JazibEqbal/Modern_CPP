#include "functionalities.h"
#include "SensorReading.h"
#include <iostream>
#include <functional>
#include <numeric>
#include <limits>
#include <variant>
#include <memory>
#include <list>
#include<vector>
#include "ReadingType.h"

using myVariant = std::variant<int, std::string>;
using myPointer = std::list<std::unique_ptr<SensorReading>>;
using object = std::unique_ptr<SensorReading>;

std::function<myVariant( myPointer &)> findSensorIdWithHighestReading =
    []( std::list<std::unique_ptr<SensorReading>> &readings){

        auto itr = std::max_element(readings.begin(),readings.end(),[](object &obj1, object &obj2){
            return obj1->getReadingValue() < obj2->getReadingValue();
        });
        return (*itr)->getSensorId();
};

// Lambda function to find the average sensor reading value for the given sensor IDs
std::function<float(myPointer &obj, std::list<myVariant> &id)> findAverageSensorReadingValue =
    [](const myPointer &readings, const std::list<myVariant> &sensorIds)
{
    if (readings.empty() || sensorIds.empty())
    {
        return 0.0f;
    }
    float total=0;
    int count=0;
    for(auto &itr: sensorIds){ //sensor id mein loop lagao
        for(auto &it: readings){
            if(it->getSensorId() == itr){
                total +=it->getReadingValue();
                count++;
            }
        }
    }
    return total/count;
};

// // Lambda function to find the reading status for one sensor whose ID is passed as a parameter
std::function<READING_TYPE(myPointer &obj, myVariant)> findSenorId =
    [](myPointer &obj, myVariant sensorid)
{
    auto itr = std::find_if(obj.begin(),obj.end(),[&](object &s){
            return s->getSensorId() == sensorid;
    });
    return (*itr)->getType();
};

std::function<std::optional<myPointer>(myPointer &,float)> findReadingsAboveThreshold =
    [](const myPointer &readings, float threshold)
{
    myPointer result(readings.size());

    auto itr = std::copy_if(readings.begin(),readings.end(),result.begin(),[threshold](object &obj){
        return obj->getReadingValue() > threshold;
    });
    result.resize(std::distance(result.begin(),itr));

    return result;
};

// // Lambda function to find the first N sensors from the Data container
// std::function<myPointer(const myPointer &, int)> findFirstNSensors =
//     [](const myPointer &readings, int N)
// {
//     int count = 0;
//     myPointer result;

//     auto it = readings.begin();
//     for (int i = 0; i < count; i++)
//     {
//         std::visit([&result](const auto &data)
//                    { result.emplace_back(std::make_unique<SensorReading>(data)); },
//                    (*it)->getSensorId());
//         it++;
//     }
//     return result;
// };
