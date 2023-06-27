#include "Manufacture.h"
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

int main()
{
    Conatiner data;

    createEnteries(data);
    std::cout << "Count of car units is " << countCarUnits(data, 20000) << "\n";
    std::cout<<"Average HorsePower is: "<<averageOfHorsePower(data)<<"\n";
    std::cout << "Combined insurance amount is " << combinedInsuranceCost(data) << "\n";
    std::cout<<"Model is:"<<modelOfMaximumHorsePower(data)<<"\n";

    auto res1 = uniqueCarBrands(data);
    if (res1.has_value())
    {
        std::cout<<"Unique Brands are\n";
        for (auto &it : res1.value())
        {
            std::cout << displayManufacturer(it) << "\n";
        }
    }
    else
    {
        std::cout << "No values\n";
    }

    auto ans = modelsAboveThreshold(data, 45000);
    if (ans.has_value())
    {
        std::cout<<"Models above threshold are\n";
        for (auto &it : ans.value())
        {
            std::cout << it << "\n";
        }
    }
    else
    {
        std::cout << "No values\n";
    }
}