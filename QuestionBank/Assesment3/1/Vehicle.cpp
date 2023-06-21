#include "Vehicle.h"

Vehicle::Vehicle(myVariant id, int registration, VEHICLE_TYPE type, refWrapper plan)
    : vehicleId{id}, vehicleRegistration{registration}, vehiceType{type}, vehicleInsurancePlan{plan} {}

Vehicle::~Vehicle()
{
    std::cout<<"Insurance with id destroyed!\n";
}

std::string displayVehicleEnum(VEHICLE_TYPE type){
    if(type == VEHICLE_TYPE::SPECIAL_PURPOSE){
        return "SPECIAL_PURPOSE";
    } else if(type == VEHICLE_TYPE::COMMERCIAL){
        return "COMMERCIAL";
    } else {
        return "PRIVATE";
    }
}

std::ostream &operator<<(std::ostream &os, const Vehicle &rhs) {
    os << " Vehcile Id: "; 
    std::visit( [&](auto arg){ os<< arg; }  , rhs.vehicleId);
      os << " vehicleRegistration: " << rhs.vehicleRegistration
       << " vehiceType: " <<displayVehicleEnum(rhs.vehiceType)
       << " vehicleInsurancePlan: " << rhs.vehicleInsurancePlan.get()->getInsuranceAmount();
    return os;
}