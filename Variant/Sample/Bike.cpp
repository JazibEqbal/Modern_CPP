#include "Bike.h"

Bike::Bike(std::string id, float price, std::string model) : Vehicle(id,price), bikeModel{model} {}

Bike::~Bike()
{
    std::cout<<"Bike\n";
}

void Bike::calculateRtoTax()
{
    std::cout<<"Bike tax is "<<.01f* this->getVehiclePrice()<<"\n";
}