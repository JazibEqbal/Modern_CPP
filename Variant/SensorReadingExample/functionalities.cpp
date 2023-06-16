#include "functionalities.h"

std::function<std::variant<int, std::string>(std::list<std::unique_ptr<SensorReading>> &obj)> findSensorIdWithHighestReading =
    [](std::list<std::unique_ptr<SensorReading>> &readings)
{
    std::variant<int, std::string> maxSensorId;
    auto max = readings.front().get()->getReadingValue();

    for (auto &it : readings)
    { // std::visit is a function that applies a lambda function to the values stored in a std::variant
        std::visit([&](auto &sensorId, float &readingValue)
                   {
            if (readingValue > max) {
                max = readingValue;
                maxSensorId = sensorId;
            } },
                   it.get()->getSensorId(), it.get()->getReadingValue()); // retrives the current value id and value  and sets argument to this
    }
    return maxSensorId;
};

std::function<float(std::list<std::unique_ptr<SensorReading>> &obj, std::variant<int, std::string> id)> avgReadingValue =
    [](std::list<std::unique_ptr<SensorReading>> &obj, std::variant<int, std::string> id)
{
    float avg = 0.0f;
    std::for_each(obj.begin(), obj.end(), [&](std::unique_ptr<SensorReading> &s)
                  { std::visit([&](float reading, auto &sensor)
                               {
                    if(s.get()->getSensorId() == id) {
                        avg += reading;
                    } },
                               s.get()->getReadingValue(), s.get()->getSensorId()); });
    return avg;
};

std::function<READING_TYPE(std::list<std::unique_ptr<SensorReading>> &obj, std::variant<int, std::string> id)> findSenorId =
    [](std::list<std::unique_ptr<SensorReading>> &obj, std::variant<int, std::string> id)
{
    READING_TYPE type;
    std::for_each(obj.begin(), obj.end(), [](std::unique_ptr<SensorReading> &s)
                  { std::visit([&](auto &sensorid)
                               {
                    if(s.get()->getSensorId() == id){
                        type = s.get()->getType();
                    } },
                               s.get()->getSensorId()); });
    return type;
};

std::function<std::list<SensorReading>(std::list<std::unique_ptr<SensorReading>> &obj, float val)> instancesAboveThreshold =
    [](std::list<std::unique_ptr<SensorReading>> &obj, float val)
{
    std::list<SensorReading> list;

    std::for_each(obj.begin(), obj.end(), [](std::unique_ptr<SensorReading> &s)
                  { std::visit([&](auto &sensor, float value)
                               {
                if(value > val){
                    list.push_back(s);
                } },
                               s.get()->getSensorId(), s.get()->getReadingValue()); });
    return list;
};

// std::function<std::list<SensorReading>(std::list<std::unique_ptr<SensorReading>> &obj, int n)> firstNSensors =
//     [](std::list<std::unique_ptr<SensorReading>> &obj, int n)
// {
//     std::list<SensorReading> list(obj.size());
//     int count = 0;
//     std::for_each(obj.begin(), obj.end(), [](std::unique_ptr<SensorReading> &s)
//                   { std::visit([&]()
//                                {
//                 if(count <= n){

//                 } }) })
// };
