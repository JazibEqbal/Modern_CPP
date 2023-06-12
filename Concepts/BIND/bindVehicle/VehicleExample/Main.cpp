#include "Car.h"
#include "Vehicle.h"
#include "VehicleType.h"
#include <iostream>
#include <list>
#include "Functionalities.h"
#include <functional>

int main()
{
    std::list<Vehicle *> vehicles;
    vehicles.push_back(new Car("Brand1", VehicleType::SEDAN, 50000.0f, "Vehicle3"));
    vehicles.push_back(new Car("Brand2", VehicleType::SUV, 80000.0f, "Vehicle3"));
    vehicles.push_back(new Car("Brand3", VehicleType::ELECTRIC_SUV, 60000.0f, "Vehicle3"));

    std::function<float(std::list<Vehicle *> &)> boundAverageVehicleType =
        std::bind(averageVehicleType, std::placeholders::_1);

    float avgPrice = boundAverageVehicleType(vehicles);
    std::cout << "Average Vehicle Price: " << avgPrice << std::endl;
    //
    std::function<void(const std::list<Vehicle *> &, VehicleType)> boundFindGivenVehicleType =
        std::bind(findGivenVehicleType, std::placeholders::_1, std::placeholders::_2);
    boundFindGivenVehicleType(vehicles, VehicleType::SUV);
    //
    std::list<VehicleType> types = {VehicleType::SUV, VehicleType::SEDAN};

    std::function<int(const std::list<Vehicle *> &, const std::list<VehicleType> &)> boundCountOfGivenTypes =
        std::bind(countOfGivenTypes, std::placeholders::_1, std::placeholders::_2);

    int count = boundCountOfGivenTypes(vehicles, types);
    std::cout << "Count of Given Types: " << count << std::endl;

    // for (const auto& vehicle : vehicles) {
    //     delete vehicle;
    // }

    return 0;
}
