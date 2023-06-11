#include "functionalities.h"

void operation(std::list<VehcileData *> &v, std::list<std::function<float(std::list<VehcileData *> &veh)>> fun)
{
    for (auto &it : fun)
    {
        std::cout << it(v) << "\n";
    }
}

std::function<float(std::list<VehcileData *> obj)> AverageFuelCapacity =
    [](std::list<VehcileData *> obj)
{
    float sum = 0.0f;
    int count = 0;
    if (obj.empty())
    {
        throw std::runtime_error("list is empty");
    }
    for (auto *it : obj)
    {
        sum += it->getFuelTankCapacity();
        count++;
    }
    return sum / count;
};

std::function<float(std::list<VehcileData *> obj)> FindMileage = [](std::list<VehcileData *> obj)
{
    float val;
    std::string id;
    std::cin >> id;
    for (auto *it : obj)
    {
        if (id == it->getVehicleId())
            val = it->getMileage();
    }
    return val;
};