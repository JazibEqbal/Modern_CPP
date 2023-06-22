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

using CarPointer = std::shared_ptr<Car>; // shared pointer of Car Type
using container = std::list<CarPointer>; // list of Car Pointers

/*
    a) if container is empty throwing error of empty passed list
    b) if threshold is negative throwing an error
    c) copying the items into a new list if threshold value is above insurance amount
    d) resising the list to the number of items in the new list
    e) if list size is equal to 0 returning an empty list
        -- else returning the desired list
*/

std::function<std::optional<container>(container &data, float threshold)> AboveThreshold = [](container &data, float threshold)
{
    container list(data.size());

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
        return container();
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
std::function<std::optional<std::list<float>>(container &data, VEHICLE_TYPE type)> accumulatePriceOfMatchedVehicleType =
    [](container &data, VEHICLE_TYPE type)
{
    std::list<float> list(data.size());
    if (data.empty())
    {
        throw std::runtime_error("Data passed is empty");
    }
    auto itr = std::transform(data.begin(), data.end(), list.begin(), [&](CarPointer &obj)
                              { return obj.get()->getCarPrice() && obj->getVehicleType() == type; });
    list.resize(std::distance(list.begin(), itr));
    if (list.size() == 0)
    {
        return std::list<float>{};
    }
    else
    {
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

std::function<std::optional<std::list<std::string>>(std::future<container> &data)> matchingCarColour =
    [](std::future<container> &data)
{
    auto res = data.get();
    std::list<std::string> list(res.size());

    if (res.empty()) // checking exceptions
    {
        throw std::runtime_error("Data passed is empty");
    }
    auto itr = std::transform(res.begin(), res.end(), list.begin(), [&](CarPointer &obj)
                              { return obj->getCarPrice() && obj->getVehicleType() == VEHICLE_TYPE::PRIVATE; }); // resizing the list
    list.resize(std::distance(list.begin(), itr));

    if (list.size() == 0)
    {
        return std::optional<std::list<std::string>>(); // returning empty list if no value matches the VehicleType
    }
    else
    {
        return std::optional<std::list<std::string>>(list);
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

    for (auto &obj : data)
    {
        if (obj->getVehicleType() == VEHICLE_TYPE::COMMERCIAL &&
            obj->getVehicleRegistration() == 2023 &&
            obj->getVehicleInsurancePlan().get()->getInsuranceType() == INSURANCE_TYPE::ZERO_DEBT)
        {
            total += obj->getVehicleInsurancePlan().get()->getInsuranceAmount();
            count++;
        }
    }
    return total == 0 ? 0.0f : total / count;
};
