#include "Vehicle.h"

Vehicle::Vehicle(std::string id, wrapper model, VEHICLE_SERVICE_PACKAGE_TYPE type) 
    : vehicleId{id}, vehicleModel{model}, vehicleServicePackageType{type} {}

Vehicle::~Vehicle()
{
    std::cout<<"Vehicle Destroyed\n";
}

std::ostream &operator<<(std::ostream &os, const Vehicle &rhs) {
    os << "vehicleId: " << rhs.vehicleId
       << " vehicleModel: " << rhs.vehicleModel
       << " vehicleServicePackageType: " <<displayServicePackageType(rhs.vehicleServicePackageType);
    return os;
}

std::string displayServicePackageType(VEHICLE_SERVICE_PACKAGE_TYPE type){
    if(type ==VEHICLE_SERVICE_PACKAGE_TYPE::SUBSCRIPTION){
        return "SUBSCRIPTION";
    } else if(type == VEHICLE_SERVICE_PACKAGE_TYPE::FREE){
        return "FREE";
    } else{
        return "PAID";
    }
}