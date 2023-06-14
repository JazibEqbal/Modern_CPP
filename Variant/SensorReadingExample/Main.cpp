#include <iostream>
#include "SensorReading.h"
#include "Readings.h"
#include <variant>
#include <array>
#include <list>
#include <algorithm>

// auto FindSensorId = [](std::list<SensorReading *> &obj)
// {
//     float max = 0.0f;
//     auto itr = obj.begin();
//     auto type = obj.front()->getSensorId();
//     for (auto itr= obj.begin(); itr != obj.end(); itr++)
//     {
//        [=](Type *arg) mutable{
//                     if((*itr)->getReadingValue() > max){
//                     max = (*itr)->getReadingValue();
//                     type = (*itr)->getSensorId();
//             } };
//     };
//     // while(itr != obj.end()){
//     //     std::visit([](auto arg){
//     //         if((*itr)->getReadingValue() > max){
//     //             max = (*itr)->getReadingValue();
//     //             type = arg->getSensorId();
//     //         }
//     //     });
//     //     itr++;
//     // }
//     return type;
// };

// auto FindAverageSensorReading = [](std::array<SensorReading *, 5> &obj, std::list<Type *> &id)
// {
//     float value = 0.0f;
//     int count = 0;
//     for (auto &it : obj)
//     {
//         for (auto sensor : id)
//         {
//             std::visit([](auto arg)
//                        {
//                 if(arg->getSensorId() == sensor.){
//                 value = arg->getReadingValue();
//                 count++;
//                 } },
//                        it);
//         }
//     }
//     return value / count;
// };

// auto FindReadingType = [](std::array<SensorReading *, 5> &obj, Type id)
// {
//     std::visit([](auto arg)
//                {
//                 if(arg->getSensorId() == id){
//                     return arg->getType();
//                 } },
//                obj);
// };

// auto FindSensorReadingAboveThreshold = [](std::array<SensorReading *, 5> &obj, float threshold)
// {
//     std::list<SensorReading *> list(obj.size());
//         std::visit([](auto arg)
//                    { std::copy_if(list.begin(),
//                                   list.end(),
//                                   [](SensorReading *s)
//                                   {
//                                       return s->getReadingValue() > threshold;
//                                   }); },
//                    obj);
//     return list;
// };

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

int main()
{
    SensorReading *s1 = new SensorReading(1, "1x", READING_TYPE::ACCEPTABLE, 100.0f);
    SensorReading *s2 = new SensorReading(2, "2x", READING_TYPE::DEFAULT, 200.0f);
    SensorReading *s3 = new SensorReading(1, "1x", READING_TYPE::ACCEPTABLE, 100.0f);
    SensorReading *s4 = new SensorReading(2, "2x", READING_TYPE::DEFAULT, 200.0f);
    SensorReading *s5 = new SensorReading(1, "1x", READING_TYPE::ACCEPTABLE, 100.0f);
    std::list<SensorReading *> data = {s1, s2, s3, s4, s5};

}
