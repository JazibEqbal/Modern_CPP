#ifndef CAR_H
#define CAR_H
#include<iostream>
#include "Vehicle.h"
class Car : public Vehicle
{
private:
    std::string carModel;
public:
    Car()=delete;
    Car(const Car& obj) = default;
    Car(std::string id,float price,std::string model);
    ~Car();

    void calculateRtoTax() override;
};

#endif // CAR_H
