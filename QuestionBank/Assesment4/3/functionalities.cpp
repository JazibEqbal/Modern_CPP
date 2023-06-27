#include "functionalities.h"
#include "Insurance.h"
#include "Vehicle.h"
#include "Car.h"
#include "Insurancetype.h"
#include "VehicleType.h"
#include "Car.h"
#include <iostream>
#include <optional>
#include <memory>
#include <functional>
#include <algorithm>
#include <numeric>
#include <list>
#include <vector>

using CarPointer = std::shared_ptr<Car>; // shared pointer of Car Type
using container = std::list<CarPointer>; // list of Car Pointers

using myVariant = std::variant<int, std::string>; //variant of type it or string

/*
    - checking if passed set is empty or not, if empty throwing error
    - checking if all passed values matches the passed car type or not
    - return true for yes or no for false
*/
std::function<void(container &, CAR_TYPE)> checkMatchingCarType =
    [](container &data, CAR_TYPE type)
{
    if (data.empty()) // checking exception if list passed is empty
    {
        throw std::runtime_error("List passed is empty");
    }
    std::all_of(data.begin(), data.end(), [&](CarPointer &obj)
                { return obj->getCarType() == type; });
};

/*
    - checking if passed set is empty or not, if empty throwing error
    - finding min_element from the entire dataset on insurance amount
    - finding max_element from the entire dataset on insurance amount
    - finally displaying both min and max 
*/
std::function<void(container &)> vechicleIDMinMax = [](container &data)
{
    if (data.empty()) // checking exception if list passed is empty
    {
        throw std::runtime_error("List passed is empty");
    }
    auto minVehicleId = std::min_element(data.begin(), data.end(), [](CarPointer &obj1, CarPointer &obj2)
                                         { return obj1->getVehicleInsurancePlan().get()->getInsuranceAmount() <
                                                  obj2->getVehicleInsurancePlan().get()->getInsuranceAmount(); });

    auto maxVehicleId = std::max_element(data.begin(), data.end(), [](CarPointer &obj1, CarPointer &obj2)
                                         { return obj1->getVehicleInsurancePlan().get()->getInsuranceAmount() <
                                                  obj2->getVehicleInsurancePlan().get()->getInsuranceAmount(); });

    auto min = (*minVehicleId)->getVehicleId();
    auto max = (*maxVehicleId)->getVehicleId();
    std::visit([](auto &&arg)
               { std::cout << arg; },
               min);
    std::cout << "\n";

    std::visit([](auto &&arg)
               { std::cout << arg; },
               max);
};

/*
    - checking if passed set is empty or not, if empty throwing error
    - counting if it satisifies the given codintion
    - finally returning the total count
*/
std::function<int(container &, VEHICLE_TYPE, int)> countOfCarForMatchingTypeAndYear =
    [](container &data, VEHICLE_TYPE type, int year)
{
    if (data.empty()) // checking exception if list passed is empty
    {
        throw std::runtime_error("List passed is empty");
    }
    if(year <= 0) {
        throw std::runtime_error("Threshold can't be a negative value");
    }
    int count = 0;
    count = std::count_if(data.begin(), data.end(), [&](CarPointer &obj)
                          { return (obj->getVehicleType() == type && obj->getVehicleRegistration() == year); });
    return count;
};

/*
    - checking if passed set is empty or not, if empty throwing error
    - declaring a container to hold objects
    - copying if it satisifies the given condition
    - resizing the list
    - check if container size is still 0 or above, if 0 returning empty container else the container of objects
*/
std::function<std::optional<container>(container &, VEHICLE_TYPE, std::string)> instanceOfCars =
    [](container &data, VEHICLE_TYPE type, std::string color)
{
    if (data.empty()) // checking exception if list passed is empty
    {
        throw std::runtime_error("List passed is empty");
    }
    container objects(data.size());

    auto itr = std::copy_if(data.begin(), data.end(), objects.begin(), [&](CarPointer &obj)
                            { return (obj->getVehicleInsurancePlan().get()->getInsuranceType() == INSURANCE_TYPE::ZERO_DEBT && obj->getVehicleType() == type && obj->getCarColour() == color); });

    objects.resize(std::distance(objects.begin(), itr));

    if (objects.size() == 0)
    {
        return container();
    }
    else
    {
        return objects;
    }
};

/*
    - checking if passed set is empty or not, if empty throwing error
    - declaring a container to hold objects
    - transforming if it satisifies the given condition
    - resizing the list
    - check if container size is still 0 or above, if 0 returning empty container else the container of objects
*/
std::function<std::optional<std::list<float>>(container &)> carUnitTaxPrice =
    [](container &data)
{
    if (data.empty()) // checking exception if list passed is empty
    {
        throw std::runtime_error("List passed is empty");
    }
    std::list<float> list(data.size());

    if (data.empty()) // throwing error if list passed is empty
    {
        throw std::runtime_error("List passed is empty");
    }
    std::transform(data.begin(),
                   data.end(),
                   list.begin(),
                   [](CarPointer &obj)
                   {
                       return 0.1 * obj->getCarPrice();
                   });
    if (list.size() == 0)
    {
        return std::list<float>();
    }
    else
    {
        return list;
    }
};

/*
    - checking if passed set is empty or not, if empty throwing error
    - finding first element which satisfies the given condition
    - returning the vehicle id of variant type
*/
std::function<myVariant(container &, myVariant)> firstMatchingInstance =
    [](container &data, myVariant id)
{
    if (data.empty()) // checking exception if list passed is empty
    {
        throw std::runtime_error("List passed is empty");
    }
    auto itr = std::find_if(data.begin(), data.end(), [&](CarPointer &obj)
                            { return obj->getVehicleId() == id; });
    return (*itr)->getVehicleId();
};

/*
    - checking if passed set is empty or not, if empty throwing error
    - decalring a float variable 
    - returning avg by dividing total by list of passed data set
*/
std::function<float(container &)> calculateAverageOfAllCarInstances =
    [](container &data)
{
    if (data.empty()) // checking exception if list passed is empty
    {
        throw std::runtime_error("List passed is empty");
    }
    float total = 0.0f;
    total = std::accumulate(data.begin(), data.end(), 0.0f, [](float val, CarPointer& obj)
                             { return val + obj->getCarPrice(); });
    return total / data.size();
};

/*
    - checking if passed set is empty or not, if empty throwing error
    - declaring a container of CAR TYPE
    - copying if it satisifies the given condition
    - resizing the list
    - check if container size is still 0 or above, if 0 returning empty container else the container of objects
*/
std::function<std::optional<std::list<CarPointer>>(container &, float)> carTypeAboveThreshold =
    [](container &data, float threshold)
{
    if (data.empty()) // checking exception if list passed is empty
    {
        throw std::runtime_error("List passed is empty");
    }
    if(threshold < 0) {
        throw std::runtime_error("Threshold can't be a negative value");
    }
    std::list<CarPointer> list(data.size());

    auto itr = std::copy_if(data.begin(), data.end(), list.begin(), [&](CarPointer &obj)
                            { return obj->getVehicleInsurancePlan().get()->getInsuranceAmount() > threshold; });
    list.resize(std::distance(list.begin(), itr));

    if (list.size() == 0)
    {
        return std::list<CarPointer>();
    }
    else
    {
        return list;
    }
};