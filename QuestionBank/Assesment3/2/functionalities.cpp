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
std::function<std::optional<std::list<float>>(container &)> carUnitPrice = [](container &data)
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
    if (v.size() == 0)
    {
        return std::list<float>();
    }
    else
    {
        return v;
    }
};

/*
    a) checking exception if list passed is empty
    b) waiting to get input from user
    c) findind if passed number matches carUnitNumber
    d) returning the carType for matching result
*/
std::function<void(container &data, std::future<std::string> &fu)> matchingCarUnitType =
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
    if (*itr == nullptr)
    {
        std::cout << "No car unit found\n";
    }
    else
    {
        std::cout << "Car unit with number " << number << " is: " << displayCarUnit((*itr)->getCarUnitType()) << "\n";
    }
};

// /*
//     a) creating vector to store results
//     b) waiting to get input from user
//     c) copying if it satisfies the given condition
// */
std::function<void(container &data, std::future<float> &fu)> capacityAboveThreshold =
    [](container &data, std::future<float> &fu)
{
    std::vector<float> res(data.size());
    if (data.empty()) // checking exception if list passed is empty
    {
        throw std::runtime_error("List passed is empty");
    }
    auto threshold = fu.get();
    if (threshold < 0)
    {
        throw std::runtime_error("Threshold can't be a negative value");
    }

    auto itr = std::transform(data.begin(), data.end(), res.begin(), [&](mypointer &obj)
                              { if (obj->getCarUnitCostPrice() > threshold){
                                return obj->getCarUnitFuelTankCapacity();
                            }else{
                                return 0;
                            }});
    res.resize(std::distance(res.begin(), itr));
    std::remove(res.begin(),res.end(),0.0f);
    if (res.size() == 0)
    {
        std::cout<<"No car unit is abobe threshold\n";
    }else{
        for(auto &it: res){
            if(it !=0){
                std::cout<<it<<" ";
            }
        }
    }
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

// /*
//     a) creating vector to store results
//     b) waiting to get input from user
//     c) copying if it satisfies the given condition
//     d) resizing the list
//     e) returning the final result
// */
std::function<void(std::future<float> &,container &) >  allMatchingInstanceOfCar =
    [](std::future<float> &fu, container &data)
{
    std::vector<mypointer> vector(data.size());

    if (data.empty()) // checking exception if list passed is empty
    {
        throw std::runtime_error("List passed is empty");
    }
    auto price = fu.get();
    auto itr = std::copy_if(data.begin(), data.end(), vector.begin(), [&](mypointer &obj)
                            { return obj->getCarUnitCostPrice() <= price && obj->getCarUnitFuelTankCapacity() > 40 && obj->getCarUnitSeatCount() > 4; });
    vector.resize(std::distance(vector.begin(), itr)); // resizing vector size here
    if (vector.size() == 0)
    {
        std::cout<<"No car unit is satisfies\n";
    }else{
        for(auto &it: vector){
            std::cout<<*it<<"\n";
        }
    }
};
