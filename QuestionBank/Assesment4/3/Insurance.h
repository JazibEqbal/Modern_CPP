#ifndef INSURANCE_H
#define INSURANCE_H
#include "Insurancetype.h"

#include<iostream>

class Insurance
{
private:
//data member 
    std::string insuranceId;
    float insuranceAmount;
    INSURANCE_TYPE insuranceType;  //enum for categorical data
public:
//data member functions
    Insurance() = delete;
    Insurance(const Insurance &obj) = default;
    Insurance(std::string id,float amount,INSURANCE_TYPE type);
    ~Insurance();

    //Getters and setters
    std::string getInsuranceId() const { return insuranceId; }
    void setInsuranceId(const std::string &insuranceId_) { insuranceId = insuranceId_; }

    float getInsuranceAmount() const { return insuranceAmount; }
    void setInsuranceAmount(float insuranceAmount_) { insuranceAmount = insuranceAmount_; }

    INSURANCE_TYPE getInsuranceType() const { return insuranceType; };

    //friend function
    friend std::ostream &operator<<(std::ostream &os, const Insurance &rhs);
};
//display enum function
std::string displayInsuranceEnum(INSURANCE_TYPE type);


#endif // INSURANCE_H
