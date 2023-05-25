#include "Car.h"

Car::Car(std::string name, VehicleType type, float price, std::string brand) 
  : Vehicle(name,type,price) , carBrand{brand} {}

Car::~Car()
{
    std::cout<<"Destructor of car\n";
}

float Car::RtoTax()
{
    float tax= 0;
    if(this->getvehicleType() == VehicleType::ELECTRIC_SUV){
        tax=0;
    } else if(this->getvehicleType() == VehicleType::SUV || this->getvehicleType() == VehicleType::SEDAN){
        tax = 0.10 * getVehiclePrice();
    }
    return tax;
}

std::ostream &operator<<(std::ostream &os, const Car &rhs) {
    os << static_cast<const Vehicle &>(rhs)
       << " carBrand: " << rhs.carBrand;
    return os;
}

