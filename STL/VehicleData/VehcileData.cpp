#include "VehcileData.h"

VehcileData::VehcileData(std::string id, std::string model, VEHICLE_TYPE type, int capacity, float mile)
    : vehicleId{id}, vehicleModel{model}, vehicleType{type}, fuelTankCapacity{capacity}, mileage{mile}
{
}

VehcileData::~VehcileData()
{
    std::cout<<"Destroyed\n";
}

int VehcileData::operator+(const VehcileData &obj)
{
    fuelTankCapacity = fuelTankCapacity + obj.fuelTankCapacity;
    return fuelTankCapacity;
}

std::string displayType(enum class VEHICLE_TYPE type){
    if(type == VEHICLE_TYPE::HATCHBACK){
        return "HATCHBACK";
    } else if(type == VEHICLE_TYPE::SEDAN){
        return "SEDAN";
    } else{
        return "SUV";
    }
}


std::ostream &operator<<(std::ostream &os, const VehcileData &rhs) {
    os << "vehicleId: " << rhs.vehicleId
       << " vehicleModel: " << rhs.vehicleModel
       << " vehicleType: " <<displayType(rhs.vehicleType)
       << " fuelTankCapacity: " << rhs.fuelTankCapacity
       << " mileage: " << rhs.mileage;
    return os;
}