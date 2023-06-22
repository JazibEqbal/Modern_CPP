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
    std::shared_ptr<Insurance> insurance = std::make_shared<Insurance>("1", 2300.0f, INSURANCE_TYPE::ZERO_DEBT);
    std::shared_ptr<Insurance> insurance2 = std::make_shared<Insurance>("1", 300.0f, INSURANCE_TYPE::ZERO_DEBT);

    std::shared_ptr<Vehicle> vehicle1 = std::make_shared<Vehicle>(1,2023,VEHICLE_TYPE::COMMERCIAL,std::ref(insurance));
    std::shared_ptr<Vehicle> vehicle2 = std::make_shared<Vehicle>(2,555,VEHICLE_TYPE::PRIVATE,std::ref(insurance));

    data.emplace_back(std::make_shared<Car>(1, 2023, VEHICLE_TYPE::COMMERCIAL, std::ref(insurance), CAR_TYPE::SEDAN, 100.0f, "BLACK"));
    data.emplace_back(std::make_shared<Car>(2, 222, VEHICLE_TYPE::PRIVATE, std::ref(insurance), CAR_TYPE::SUV, 200.0f, "RED"));
    data.emplace_back(std::make_shared<Car>(3, 2023, VEHICLE_TYPE::COMMERCIAL, std::ref(insurance2), CAR_TYPE::SEDAN, 300.0f, "BLUE"));

    auto result = AboveThreshold(data, 100.0f);
    if (result.has_value())
    {
        for (auto &it : result.value())
        {
            std::cout << *it << "\n";
        }
    }
    else
    {
        std::cout << "No one is above threshold\n";
    }

    auto ans =getEnum();
    std::promise<VEHICLE_TYPE> pr1;
    std::future<VEHICLE_TYPE> input = pr1.get_future();
    std::future<std::optional<std::list<float>>> r1 = std::async(std::launch::async,accumulatePriceOfMatchedVehicleType,std::ref(data),ans);
    
    pr1.set_value(ans);
    
    std::promise<container> pr2;
    std::future<container> inputData = pr2.get_future();
    std::future<std::optional<std::list<std::string>>> r2 = std::async(std::launch::async,matchingCarColour,std::ref(inputData));
    pr2.set_value(data);
    r1.get();
    r2.get();

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

// std::thread t2(accumulatePriceOfMatchedVehicleType, std::ref(data), std::ref(ans));
