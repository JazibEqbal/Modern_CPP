#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H
#include "SensorReading.h"
#include<iostream>
#include<functional>
#include<numeric>
#include<limits>
#include <variant>
#include<memory>
#include<list>
#include "ReadingType.h"

extern std::function<std::variant<int,std::string>(std::vector<std::unique_ptr<SensorReading>> &obj) > findSensorIdWithHighestReading;

//find avg sensor reading value for all sensors whose IDs are passed in a data container to the lambda function
extern std::function<float(std::list<std::unique_ptr<SensorReading>> &obj, std::variant<int,std::string> id) > avgReadingValue;

//find the reading type for ONE Sensor whose ID is passed as a paramter
extern std::function<READING_TYPE(std::list<std::unique_ptr<SensorReading>> &obj, std::variant<int,std::string>) > findSenorId;

//find and return instances of SensonReading whose sensor reading value is above a threshold 
//paramter passed as an argument to the lambda

extern std::function<std::list<SensorReading>(std::list<std::unique_ptr<SensorReading>> &obj, float val) > instancesAboveThreshold;

//find the first N sensors amongst the Data container where 0<=N<=size of the container
// and N is provided as an argument to the lambda

extern std::function<std::list<SensorReading>(std::list<std::unique_ptr<SensorReading>> &obj, int n) > firstNSensors;

#endif // FUNCTIONALITIES_H



// auto FindFirstNSensors = [](std::array<SensorReading *, 5> &obj, int N)
// {
//     std::list<SensorReading *> list(obj.size());

//     int count = 0;
//     std::visit([](auto arg)
//                {
//         for(auto *a:obj){
//             if(count <= N){
//                 list.push_back(a);
//             }
//             count++;
//         } },
//                obj);
//     return list;
// };















// std::variant<int, std::string> hh(const std::vector<SensorReading> &readings)
// {
//     std::variant<int, std::string> maxSensorId;
//     float maxReadingValue = readings.front().getReadingValue();

//     for (const SensorReading &it : readings)
//     {
//         std::visit([&](auto &sensorId, float &readingValue)
//                    {
//             if (readingValue > maxReadingValue) {
//                 maxReadingValue = readingValue;
//                 maxSensorId = sensorId;
//             } },
//                    it.getSensorId(), it.getReadingValue());
//     }

//     return maxSensorId;
// }