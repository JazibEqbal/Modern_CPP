#include "Functionalities.h"

std::function<float(const std::list<Vehicle *> &vehicles)> averageVehicleType = [](const std::list<Vehicle *> &vehicles)
{
    float total = 0.0f;
    int count = 0;
    for (const auto &vehicle : vehicles)
    {
        total += vehicle->getVehiclePrice();
        count++;
    }

    return (count > 0) ? (total / count) : 0.0f;
};

void findGivenVehicleType(const std::list<Vehicle *> &vehicles, VehicleType type)
{
    for (const auto &vehicle : vehicles)
    {
        if (vehicle->getvehicleType() == type)
        {
            std::cout << "Vehicle Type: " << static_cast<int>(vehicle->getvehicleType()) << std::endl;
            std::cout << vehicle->getVehicleName() << "\n";
        }
    }
}

std::function<int(const std::list<Vehicle *> &vehicles, const std::list<VehicleType> &types)> countOfGivenTypes = [](const std::list<Vehicle *> &vehicles, const std::list<VehicleType> &types) -> int
{
    int count = 0;

    for (const auto &vehicle : vehicles)
    {
        if (std::find(types.begin(), types.end(), vehicle->getvehicleType()) != types.end())
        {
            count++;
        }
    }

    return count;
};