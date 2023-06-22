#include "Vehicle.h"


std::string convertToenum(VehicleType type){
    if(type==VehicleType::COMMERCIAL){
        return "COMMERCIAL";
    }
    else if(type==VehicleType::PRIVATE){
        return "PRIVATE";
    }
    else {
        return "SPECIAL_PURPOSE";
    }
}



std::ostream &operator<<(std::ostream &os, const Vehicle &rhs) {
    os << "vehicleId: " ;
        std::visit([](auto&& arg){std::cout<<arg;},rhs.vehicleId);
    os   << " vehicleRegistration: " << rhs.vehicleRegistration
       << " vehicleType: " << convertToenum(rhs.vehicleType)
       << " vehicleInsurancePlan: " << rhs.vehicleInsurancePlan.get()->getInsuranceAmount();
    return os;
}

Vehicle::Vehicle(std::variant<int, std::string> Id, int Registration, VehicleType Type, insuranceptr InsurancePlan):
vehicleId(Id),vehicleRegistration(Registration),vehicleType(Type),vehicleInsurancePlan(InsurancePlan)
{
}
