#include "functionalities.h"
#include "CarUnit.h"
#include "CarUnitType.h"
#include <iostream>
#include <optional>
#include <functional>
#include <algorithm>
#include <list>
#include <vector>
#include <memory>
#include <future>
#include <thread>

using mypointer = std::shared_ptr<CarUnit>;
using container = std::vector<mypointer>;

/*
    adding 10% tax to each object
    storing them in a vector variable
*/
std::function<std::list<float>(container &data) > carUnitPrice = [](container &data)
{
    std::list<float> v(data.size());

    if (data.empty()) // throwing error if list passed is empty
    {
        throw std::runtime_error("List passed is empty");
    }
    std::transform(data.begin(),
                   data.end(),
                   v.begin(),
                   [](mypointer &obj)
                   {
                       return 0.1 * obj->getCarUnitCostPrice();
                   });
    return v;
};

/*
    a) checking exception if list passed is empty
    b) waiting to get input from user
    c) findind if passed number matches carUnitNumber
    d) returning the carType for matching result
*/
std::function<CAR_UNIT_TYPE(container &data, std::future<std::string> &fu)> matchingCarUnitType =
    [](container &data, std::future<std::string> &fu)
{
    if (data.empty()) // throwing error if list passed is empty
    {
        throw std::runtime_error("List passed is empty");
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(30));
    auto number = fu.get();

    auto itr = std::find_if(data.begin(), data.end(), [&](mypointer &obj)
                            { return obj->getCarUnitNumber() == number; });
    return (*itr)->getCarUnitType();
};

/*
    a) creating vector to store results
    b) waiting to get input from user
    c) copying if it satisfies the given condition
*/
std::function<std::vector<int>(container &data, std::future<int> &fu)> capacityAboveThreshold =
    [](container &data, std::future<int> &fu)
{
    std::vector<int> res(data.size());
    if (data.empty()) // checking exception if list passed is empty
    {
        throw std::runtime_error("List passed is empty");
    }
    int threshold = fu.get();
    if (threshold < 0)
    {
        throw std::runtime_error("Threshold can't be a negative value");
    }

    auto itr = std::transform(data.begin(), data.end(), res.begin(), [&](mypointer &obj)
                            { if (obj->getCarUnitCostPrice() > threshold){
                                return obj->getCarUnitFuelTankCapacity();
                            } });
    res.resize(std::distance(res.begin(), itr));
    return res;
};

/*
function to calculate registration details on the basis of specified criteria for a specific object
*/
std::function<int(mypointer &)> registrationCost = [](mypointer &obj)
{
    int cost = 0;
    if (obj->getCarUnitType() == CAR_UNIT_TYPE::BASE) // if cartype is BASE tax is 10%
    {
        cost = obj->getCarUnitCostPrice() * .1;
    }
    else if (obj->getCarUnitType() == CAR_UNIT_TYPE::EXTENDED) // if cartype is BASE tax is 15%
    {
        cost = obj->getCarUnitCostPrice() * 0.15;
    }
    else // for other car type tax is 20%
    {
        cost = obj->getCarUnitCostPrice() * 0.2;
    }
    return cost;
};

/*
    a) creating vector to store results
    b) waiting to get input from user
    c) copying if it satisfies the given condition
    d) resizing the list
    e) returning the final result
*/
std::function<std::vector<mypointer>(int price, container &data)> allMatchingInstanceOfCar =
    [](int price, container &data)
{
    std::vector<mypointer> vector(data.size());

    if (data.empty()) // checking exception if list passed is empty
    {
        throw std::runtime_error("List passed is empty");
    }

    auto itr = std::copy_if(data.begin(), data.end(), vector.begin(), [&](mypointer &obj)
                            { return obj->getCarUnitCostPrice() <= price && obj->getCarUnitFuelTankCapacity() > 40 && obj->getCarUnitSeatCount() > 4; });
    vector.resize(std::distance(vector.begin(), itr)); // resizing vector size here
    return vector;
};
