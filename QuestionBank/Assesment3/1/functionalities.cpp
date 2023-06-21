#include "functionalities.h"
#include "Car.h"
#include "CarType.h"
#include "Vehicle.h"
#include "VehicleType.h"
#include "Insurance.h"
#include "InsuranceType.h"
#include <iostream>
#include <optional>
#include <memory>
#include <functional>
#include <algorithm>
#include <numeric>
#include <list>
#include <thread>
#include <future>
#include <mutex>

using CarPointer = std::shared_ptr<Car>; // shared pointer of Car Type
using container = std::list<CarPointer>; // list of Car Pointers

std::mutex mt; // creating a mutex object
/*
    a) if container is empty throwing error of empty passed list
    b) if threshold is negative throwing an error
    c) copying the items into a new list if threshold value is above insurance amount
    d) resising the list to the number of items in the new list
    e) if list size is equal to 0 returning an empty list
        -- else returning the desired list
*/

std::function<std::optional<std::list<CarPointer>>(container &data, float threshold)> AboveThreshold = [](container &data, float threshold)
{
    std::list<CarPointer> list(data.size());

    if (data.empty())
    {
        throw std::runtime_error("Data passed is empty");
    }
    if (threshold < 0)
    {
        throw std::runtime_error("Threshold can't be a negative value");
    }
    auto itr = std::copy_if(data.begin(), data.end(), list.begin(), [&](CarPointer &obj)
                            { return obj->getVehicleInsurancePlan().get()->getInsuranceAmount() > threshold; });
    list.resize(std::distance(list.begin(), itr)); // resizing

    if (list.size() == 0)
    {
        return std::optional<std::list<CarPointer>>{};
    }
    else
    {
        return list;
    }
};

/*
    a) if container is empty throwing error of empty passed list
    b) making the thread sleep for 1 seconds to perform context switching
    c) applying lock guard at the critical condition
    d) adding car price to total if passed object vehicle type is matching to current object type
    e) returning the total
*/
std::function<std::optional<std::list<float>>(container &data,VEHICLE_TYPE type) > accumulatePriceOfMatchedVehicleType =
    [](container &data, VEHICLE_TYPE type)
{
    std::list<float> list(data.size());
    float total = 0.0f;
    if (data.empty())
    {
        throw std::runtime_error("Data passed is empty");
    }
    std::this_thread::sleep_for(std::chrono::seconds(2)); // slleping thread for 2 seconds
    std::lock_guard lk(mt);                               // applying lock guard

    auto itr =std::copy_if(data.begin(),data.end(),list.begin(),[&](CarPointer &obj){
        return obj->getCarPrice() && obj->getVehicleType() == type;
    });
    list.resize(std::distance(list.begin(), itr));
    if(list.size() == 0){
        return  std::optional<std::list<float>>{};
    }else {
        return list;
    }
};

/*
    a) if container is empty throwing error of empty passed list
    b) if threshold is negative throwing an error
    c) making the thread sleep for 1 seconds to perform context switching
    d) applying lock guard at the critical condition
    e) copying the items into a new list if vehicle type is private
    f) resising the list to the number of items in the new list
    g) if list size is equal to 0 returning an empty list
        -- else returning the desired list
*/

std::function<std::optional<std::list<std::string>>(std::future<container &> &data)> matchingCarColour =
    [](std::future<container &> &data)
{
    auto res = data.get();
    std::list<std::string> list(res.size());

    std::this_thread::sleep_for(std::chrono::seconds(2)); // thread will sleep here for context switching

    if (res.empty()) // checking exceptions
    {
        throw std::runtime_error("Data passed is empty");
    }
    std::lock_guard lk(mt); // applying lock guard
    auto itr = std::copy_if(res.begin(), res.end(), list.begin(), [&](CarPointer &obj)
                            { return obj->getCarPrice() && obj->getVehicleType() == VEHICLE_TYPE::PRIVATE; }); // resizing the list
    list.resize(std::distance(list.begin(), itr));

    if (list.size() == 0)
    {
        return std::optional<std::list<std::string>>{}; // returning empty list if list passed is empty
    }
    else
    {
        return list;
    }
};

/*
    a) if container is empty throwing error of empty passed list
    b) declaring two varibale to count satisfied conditions and to add to total
    c) accumulating carInsuranceAmount if it matches speciied criteria into total
    d) dividing total for average by count
*/

std::function<std::optional<float>(container &data)> averageInsuranceAmount =
    [](container &data)
{
    float total = 0.0f;
    int count = 0;
    if (data.empty())
    {
        throw std::runtime_error("Data passed is empty");
    }

    total = std::accumulate(data.begin(), data.end(), 0.0f, [&](float value, CarPointer &obj, int c)
                            {
        return value + obj->getVehicleInsurancePlan().get()->getInsuranceAmount() 
        && obj->getVehicleType() == VEHICLE_TYPE::COMMERCIAL 
        && obj->getVehicleRegistration() == 20203
        && obj->getVehicleInsurancePlan().get()->getInsuranceType() == INSURANCE_TYPE::ZERO_DEBT; 
        c++;
        count=c; });
    return total / count;
};