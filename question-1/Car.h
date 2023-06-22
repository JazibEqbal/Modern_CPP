#ifndef CAR_H
#define CAR_H
#include <iostream>
#include "CarType.h"
#include "Vehicle.h"
class Car:public Vehicle
{
private:

    CarType carType;
    float carPrice;
    std::string carColour;
    
public:
    Car(/* args */) =default;
    Car(
    std::variant<int,std::string> Id,
    int Registration,
    VehicleType vType,
    insuranceptr InsurancePlan,
    CarType Type,
    float Price,
    std::string Colour
    );
    ~Car() {
        std::cout<<"Car Object Destroyed!\n";
    }

    CarType getCarType() const { return carType; }
    void setCarType(const CarType &carType_) { carType = carType_; }

    float getCarPrice() const { return carPrice; }
    void setCarPrice(float carPrice_) { carPrice = carPrice_; }

    std::string getCarColour() const { return carColour; }
    void setCarColour(const std::string &carColour_) { carColour = carColour_; }
};

#endif // CAR_H
