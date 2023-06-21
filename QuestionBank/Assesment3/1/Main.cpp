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
#include <vector>
#include <future>
#include <thread>
#include <mutex>

using CarPointer = std::shared_ptr<Car>; // shared pointer of Car Type
using container = std::list<CarPointer>; // list of Car Pointers

// function to get input from user
VEHICLE_TYPE getEnum()
{
    std::cout << "Choose 1 for PRIVATE\n"
              << "Choose 2 for COMMERCIAL\n"
              << "Choose 3 for SPECIAL_PURPOSE\n";
    int choice;
    std::cin >> choice;
    switch (choice)
    {
    case 1:
        return VEHICLE_TYPE::COMMERCIAL;
        break;
    case 2:
        return VEHICLE_TYPE::PRIVATE;
        break;
    case 3:
        return VEHICLE_TYPE::SPECIAL_PURPOSE;
        break;
    default:
        return VEHICLE_TYPE::COMMERCIAL;
        break;
    }
};

int main()
{
    container data;
    std::shared_ptr<Insurance> insurance = std::make_shared<Insurance>("1", 2300.0f, INSURANCE_TYPE::REGULAR);

    data.emplace_back(std::make_shared<Car>(1, 111, VEHICLE_TYPE::COMMERCIAL, std::ref(insurance), CAR_TYPE::SEDAN, 100.0f, "BLACK"));
    data.emplace_back(std::make_shared<Car>(2, 222, VEHICLE_TYPE::PRIVATE, std::ref(insurance), CAR_TYPE::SUV, 200.0f, "RED"));
    data.emplace_back(std::make_shared<Car>(3, 333, VEHICLE_TYPE::COMMERCIAL, std::ref(insurance), CAR_TYPE::SEDAN, 300.0f, "BLUE"));

    auto ans = AboveThreshold(data, 100.0f);
    if (ans.has_value())
    {
        for (auto &it : ans.value())
        {
            std::cout << it << " ";
        }
    }
    else
    {
        std::cout << "No one is above threshold\n";
    }

    auto ans = getEnum();

    std::thread t2(accumulatePriceOfMatchedVehicleType, data, ans);

    std::thread t1(matchingCarColour,data);

    t1.join();
    t2.join();

    auto res = averageInsuranceAmount(data);
    if (res.has_value())
    {
        std::cout << res.value() << "\n";
    }
    else
    {
        std::cout << "No value to display...\n";
    }
}

// pr.set_value(ans);
// std::promise<VEHICLE_TYPE> pr;
// std::future<VEHICLE_TYPE> input = pr.get_future();
// std::future<float> r1 = std::async(std::launch::async,accumulatePriceOfMatchedVehicleType,std::ref(data),std::ref(input));