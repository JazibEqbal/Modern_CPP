#include "Car.h"

Car::Car(std::string id, float price, std::string model) : Vehicle(id,price), carModel{model} {}

Car::~Car()
{
    std::cout<<"Car\n";
}

void Car::calculateRtoTax()
{
    std::cout<<"Car Tax is "<<.1f * this->getVehiclePrice()<<"\n";
}
