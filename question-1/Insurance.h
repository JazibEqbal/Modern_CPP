#ifndef INSURANCE_H
#define INSURANCE_H
#include <iostream>
#include "InsuranceType.h"
class Insurance
{
private:
    std::string insuranceId;
    float insuranceAmount;
    InsuranceType insuranceType;


public:
    Insurance(/* args */) =default;
    Insurance(
        std::string Id,
        float Amount,
        InsuranceType Type   
    );
    ~Insurance() {
        std::cout<<"Insurance Object Destroyed!\n";
    }

    std::string getInsuranceId() const { return insuranceId; }
    void setInsuranceId(const std::string &insuranceId_) { insuranceId = insuranceId_; }

    float getInsuranceAmount() const { return insuranceAmount; }
    void setInsuranceAmount(float insuranceAmount_) { insuranceAmount = insuranceAmount_; }

    InsuranceType getInsuranceType() const { return insuranceType; }
    void setInsuranceType(const InsuranceType &insuranceType_) { insuranceType = insuranceType_; }

    friend std::ostream &operator<<(std::ostream &os, const Insurance &rhs);
};

#endif // INSURANCE_H
