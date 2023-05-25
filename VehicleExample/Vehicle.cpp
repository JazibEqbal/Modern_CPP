#include "Vehicle.h"

Vehicle::Vehicle(std::string name, VehicleType type, float price): vehicleName{name}, vehicleType{type}, vehiclePrice{price} {}

Vehicle::~Vehicle()
{
std::cout<<"Vehicle Destructor\n";
}

std::ostream &operator<<(std::ostream &os, const Vehicle &rhs) {
os << "Vehicle Name: " << rhs.vehicleName<<"\n"
    << "Vehicle Type: " << displayEnum(rhs.vehicleType)<<"\n"
    << "Vehicle Price: " << rhs.vehiclePrice<<"\n";
return os;
}

std::string displayEnum(enum class VehicleType vehicleType){
    if(vehicleType == VehicleType::SUV){
        return "SUV";
    } else if(vehicleType == VehicleType::SEDAN){
        return "SEDAN";
    } else if(vehicleType == VehicleType::ICE_TWO_WHEELER){
        return "ICE_TWO_WHEELER";
    } else if(vehicleType == VehicleType::ELECTRIC_SUV){
        return "ELECTRIC_SUV";
    } else {
        return "ELECTRIC_TWO_WHEELER";
    }
}