#ifndef BIKE_H
#define BIKE_H
#include<iostream>
#include "Vehicle.h"

class Bike : public Vehicle
{
private:
    std::string bikeModel;
public:
    Bike() = delete;
    Bike(const Bike& obj) =default;
    Bike(std::string id,float price,std::string model);
    ~Bike();

    void calculateRtoTax() override;
};

#endif // BIKE_H
