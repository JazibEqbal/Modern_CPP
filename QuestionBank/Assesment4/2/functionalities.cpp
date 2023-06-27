#include "functionalities.h"
#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <unordered_map>
#include <memory>
#include <numeric>
#include <list>

using Pointer = std::shared_ptr<Manufacture>; // shared pointer to object
using Conatiner = std::vector<Pointer>;       // creating vector of pointer objects

std::function<void(Conatiner &)> createEnteries = [](Conatiner &data)
{
    data.emplace_back(std::make_shared<Manufacture>(MANUFACTURER_TYPE::Acura, "Integra", 16919, 16360, 21500, 100));
    data.emplace_back(std::make_shared<Manufacture>(MANUFACTURER_TYPE::Acura, "RL", 8588, 29725, 42000, 210));
    data.emplace_back(std::make_shared<Manufacture>(MANUFACTURER_TYPE::Audi, "A4", 20397, 22255, 23990, 150));
    data.emplace_back(std::make_shared<Manufacture>(MANUFACTURER_TYPE::Audi, "A6", 1878, 23555, 33950, 200));
    data.emplace_back(std::make_shared<Manufacture>(MANUFACTURER_TYPE::Audi, "A8", 138, 39000, 62000, 310));
    data.emplace_back(std::make_shared<Manufacture>(MANUFACTURER_TYPE::BMW, "323i", 19747, 20000, 26990, 170));
    data.emplace_back(std::make_shared<Manufacture>(MANUFACTURER_TYPE::BMW, "328i", 9231, 28675, 33400, 193));
    data.emplace_back(std::make_shared<Manufacture>(MANUFACTURER_TYPE::BMW, "528i", 17527, 36125, 38900, 193));
    data.emplace_back(std::make_shared<Manufacture>(MANUFACTURER_TYPE::Cadillac, "Escalade", 14785, 42000, 46225, 255));
    data.emplace_back(std::make_shared<Manufacture>(MANUFACTURER_TYPE::Chervolet, "Cavalier", 145519, 9250, 13260, 115));
};

/*
    - checking if passed set is empty or not, if empty throwing error
    - counting objects if price of current object is greater than price
    - finally returning the total count
*/
std::function<int(Conatiner &, int)> countCarUnits = [](Conatiner &data, int price)
{
    if (data.empty()) // checking exception if list passed is empty
    {
        throw std::runtime_error("List passed is empty");
    }
    int count = 0;
    count = std::count_if(data.begin(), data.end(), [&](Pointer &obj)
                          { return (obj->horsepower() > 100 && obj->price() > price); });
    return count;
};

// /*
//     - checking if passed set is empty or not, if empty throwing error
//     - creating list of pointer objects
//     - copying data into list if it satisfies the criteria
//     - resizing the list
//     - finally returning the average by dividing total by size of list
// */
// std::function<float(Conatiner &)> averageOfHorsePower = [](Conatiner &data)
// {
//     if (data.empty()) // checking exception if list passed is empty
//     {
//         throw std::runtime_error("List passed is empty");
//     }
//     std::list<Pointer> list(data.size());

//     auto itr = std::copy_if(data.begin(), data.end(), list.begin(), [](Pointer &obj)
//                             { return obj->horsepower() && (obj->price() > 30000 && (obj->getManufacturer() == MANUFACTURER_TYPE::Cadillac || obj->getManufacturer() == MANUFACTURER_TYPE::Audi)); });

//     list.resize(std::distance(list.begin(), itr));

//     auto total = std::accumulate(list.begin(), list.end(), 0.0f);
//     return total / list.size();
// };

// /*
//     - checking if passed set is empty or not, if empty throwing error
//     - initializing a total varibale to 0
//     - accumulating to total based on given conditions
//     - returning the total
// */
// std::function<int(Conatiner &)> combinedInsuranceCost = [](Conatiner &data)
// {
//     if (data.empty()) // checking exception if list passed is empty
//     {
//         throw std::runtime_error("List passed is empty");
//     }
//     int total = 0;
//     total = std::accumulate(data.begin(),data.end(),0,[&](int value,Pointer &obj){
//         if(obj->getManufacturer() == MANUFACTURER_TYPE::BMW){
//             total = value + obj->price() * 0.1;
//         }else{
//             total = value + obj->price() * 0.08;
//         }
//     });
//     return total;
// };

// /*
//     - checking if passed set is empty or not, if empty throwing error
//     - creating list of pointer objects
//     - copying data into list if it satisfies the criteria
//     - resizing the list
//     - finding maximum element from the list with maximum horsepower
//     - returning the model for the max object found
// */
std::function<std::string(Conatiner &)> modelOfMaximumHorsePower = [](Conatiner &data)
{
    if (data.empty()) // checking exception if list passed is empty
    {
        throw std::runtime_error("List passed is empty");
    }
    std::list<Pointer> list(data.size());

    auto itr = std::copy_if(data.begin(),data.end(),list.begin(),[](Pointer &obj){
        return obj->horsepower() 
        && (obj->price() > 30000 && obj->resaleValue() == 20000 && obj->horsepower() > 150);
    });
    list.resize(std::distance(list.begin(),itr));
    auto itrMax = std::max_element(list.begin(), list.end(), [](Pointer &obj1, Pointer &obj2)
                                { return obj1->horsepower() < obj2->horsepower(); });

    return (*itrMax)->model();
};

// /*
//     - checking if passed set is empty or not, if empty throwing error
//     - creating a container of size of data
//     - transforming data into list based on satisfied criteria
//     - resizing the container
//     - sorting the list
//     - removing duplicates
//     - check if container size is still 0 or above, if 0 returning empty container else the container of objects
// */
std::function<std::optional<std::list<MANUFACTURER_TYPE>>(Conatiner&) > uniqueCarBrands = [](Conatiner &data)
{
    if (data.empty()) // checking exception if list passed is empty
    {
        throw std::runtime_error("List passed is empty");
    }
    std::list<MANUFACTURER_TYPE> list(data.size());

    auto itr = std::transform(data.begin(), data.end(), list.begin(), [](Pointer &obj)
                   {
            if(obj->horsepower() > 150 && obj->resaleValue() > 35000){
                return obj->getManufacturer();
            } });
    list.resize(std::distance(list.begin(),itr));
    // std::sort(list.begin(), list.end());
    std::unique(list.begin(), list.end());
    if(list.size() == 0){
        return std::list<MANUFACTURER_TYPE>();
    }else{
        return list;
    }
};

// /*
//     - checking if passed set is empty or not, if empty throwing error
//     - creating a container of size of data
//     - copying data into list based on satisfied criteria
//     - resizing the container
//     - check if container size is still 0 or above, if 0 returning empty container else the container of objects
// */
std::function<std::optional<std::list<MANUFACTURER_TYPE>>(Conatiner &, int)> modelsAboveThreshold =
    [](Conatiner &data, int threshold)
{
    if (data.empty()) // checking exception if list passed is empty
    {
        throw std::runtime_error("List passed is empty");
    }
    std::list<MANUFACTURER_TYPE> list(data.size());

    auto itr = std::transform(data.begin(), data.end(), list.begin(), [&](Pointer &obj)
                            { if(obj->price() > threshold){
                                return obj->getManufacturer();
                            } });

    list.resize(std::distance(list.begin(), itr));

    if (list.size() == 0)
    {
        return std::list<MANUFACTURER_TYPE>();
    }
    else
    {
        return list;
    }
};