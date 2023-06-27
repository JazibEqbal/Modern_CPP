#include "Insurance.h"

Insurance::Insurance(std::string id, float amount, INSURANCE_TYPE type)
    : insuranceId{id}, insuranceAmount{amount}, insuranceType{type} {}

Insurance::~Insurance()
{
    std::cout<<"Insurance with id "<<this->insuranceId<<" destroyed!\n";
}

std::string displayInsuranceEnum(INSURANCE_TYPE type)
{
    if (type == INSURANCE_TYPE::REGULAR)
    {
        return "REGULAR";
    } else {
        return "ZERO_DEBT";
    }
}

std::ostream &operator<<(std::ostream &os, const Insurance &rhs) {
    os << "insuranceId: " << rhs.insuranceId
       << " insuranceAmount: " << rhs.insuranceAmount
       << " insuranceType: " << displayInsuranceEnum(rhs.insuranceType);
    return os;
}
