#include "Insurance.h"

Insurance::Insurance(std::string Id, float Amount, InsuranceType Type):
insuranceId(Id),insuranceAmount(Amount),insuranceType(Type)
{
}


std::string convertToString(InsuranceType type){
    if(type==InsuranceType::REGULAR){
        return "REGULAR";
    }
    else if(type==InsuranceType::ZERO_DEBT){
        return "ZERO_DEBT";
    }
    else{
        return "Unknown";
    }
}
std::ostream &operator<<(std::ostream &os, const Insurance &rhs) {
    os << "insuranceId: " << rhs.insuranceId
       << " insuranceAmount: " << rhs.insuranceAmount
       << " insuranceType: " <<convertToString( rhs.insuranceType);
    return os;
}
