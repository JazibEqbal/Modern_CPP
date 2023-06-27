#include "Vehicle.h"

//user defined constructor
Vehicle::Vehicle(myVariant id, int registration, VEHICLE_TYPE type, refWrapper plan)
    : vehicleId{id}, vehicleRegistration{registration}, vehiceType{type}, vehicleInsurancePlan{plan} {}

//destructor
Vehicle::~Vehicle()
{
    std::cout<<"Insurance with id destroyed!\n";
}
//enum
std::string displayVehicleEnum(VEHICLE_TYPE type){
    if(type == VEHICLE_TYPE::SPECIAL_PURPOSE){
        return "SPECIAL_PURPOSE";
    } else if(type == VEHICLE_TYPE::COMMERCIAL){
        return "COMMERCIAL";
    } else {
        return "PRIVATE";
    }
}
//friend function 
std::ostream &operator<<(std::ostream &os, const Vehicle &rhs) {
    os << " Vehcile Id: "; 
    std::visit( [&](auto arg){ os<< arg; }  , rhs.vehicleId);
      os << " vehicleRegistration: " << rhs.vehicleRegistration
       << " vehiceType: " <<displayVehicleEnum(rhs.vehiceType)
       << " vehicleInsurancePlan: " << rhs.vehicleInsurancePlan.get()->getInsuranceAmount();
    return os;
}