#include"Veh.h"
#include<list>
#include "func.h"
int main() {
    std::list<Vehicle> vehicles;
    vehicles.emplace_back("Toyota Camry", VEHICLE_TYPE::SEDAN);
    vehicles.emplace_back("Honda CR-V", VEHICLE_TYPE::SUV);
    vehicles.emplace_back("Tesla Model X", VEHICLE_TYPE::ELECTRIC_SUV);
    vehicles.emplace_back("BMW R 1250 GS", VEHICLE_TYPE::ICE_TWO_WHEELER);
    vehicles.emplace_back("Zero SR/F", VEHICLE_TYPE::ELECTRIC_TWO_WHEELER);

    float average = findAveragePrice(vehicles);
    std::cout << "Average Price: " << average << std::endl;

    std::cout << "Vehicles of type SUV:" << std::endl;
    findGivenVehicleType(vehicles, VEHICLE_TYPE::SUV);

    std::list<VEHICLE_TYPE> types = { VEHICLE_TYPE::SUV, VEHICLE_TYPE::SEDAN };
    countOfGivenTypes(vehicles, types);

    return 0;
}
