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

using myVariant = std::variant<int, std::string>; // variant of type int or string

int main()
{
    container data;
    //objects of insurance
    std::shared_ptr<Insurance> insurance = std::make_shared<Insurance>("1", 2300.0f, INSURANCE_TYPE::ZERO_DEBT);
    std::shared_ptr<Insurance> insurance2 = std::make_shared<Insurance>("1", 300.0f, INSURANCE_TYPE::ZERO_DEBT);

    //objects of vechile type
    std::shared_ptr<Vehicle> vehicle1 = std::make_shared<Vehicle>(1, 2023, VEHICLE_TYPE::COMMERCIAL, std::ref(insurance));
    std::shared_ptr<Vehicle> vehicle2 = std::make_shared<Vehicle>(2, 555, VEHICLE_TYPE::PRIVATE, std::ref(insurance));

    //objects of car type
    data.emplace_back(std::make_shared<Car>(1, 2023, VEHICLE_TYPE::COMMERCIAL, std::ref(insurance), CAR_TYPE::SEDAN, 100.0f, "BLACK"));
    data.emplace_back(std::make_shared<Car>(2, 222, VEHICLE_TYPE::PRIVATE, std::ref(insurance), CAR_TYPE::SUV, 200.0f, "RED"));
    data.emplace_back(std::make_shared<Car>(3, 2023, VEHICLE_TYPE::COMMERCIAL, std::ref(insurance2), CAR_TYPE::SEDAN, 300.0f, "BLUE"));

    //calling all functions
    checkMatchingCarType(data, CAR_TYPE::SUV);

    vechicleIDMinMax(data);

    countOfCarForMatchingTypeAndYear(data, VEHICLE_TYPE::COMMERCIAL, 222);

    auto res = instanceOfCars(data, VEHICLE_TYPE::PRIVATE, "RED");
    if (res.has_value())
    {
        for (auto &it : res.value())
        {
            std::cout << *it << "\n";
        }
    }
    else
    {
        std::cout << "No values found\n";
    }

    auto res2 = carUnitTaxPrice(data);
    if (res2.has_value())
    {
        for (auto &it : res2.value())
        {
            std::cout << it << "\n";
        }
    }
    else
    {
        std::cout << "No values found\n";
    }

    auto ans = firstMatchingInstance(data, 2);

    std::visit([](auto &&arg)
               { std::cout << arg; },
               ans);

    std::cout << calculateAverageOfAllCarInstances(data);

    auto ans2 = carTypeAboveThreshold(data, 100);

    if (ans2.has_value())
    {
        for (auto &it : ans2.value())
        {
            std::cout << displayCarEnum(it->getCarType()) << "\n";
        }
    }
    else
    {
        std::cout << "No values found\n";
    }
}