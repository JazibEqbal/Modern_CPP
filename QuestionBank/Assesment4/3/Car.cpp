#include "Car.h"

Car::Car(myVariant id,int registration,VEHICLE_TYPE vehicleType, refWrapper plan,CAR_TYPE type, float price, std::string colour) 
: Vehicle(id,registration,vehicleType,plan), carType{type}, carPrice{price}, carColour{colour} {}

Car::~Car()
{
    std::cout<<"Car destroyed\n";
}

std::string displayCarEnum(CAR_TYPE type){
    if(type == CAR_TYPE::HATCHBACK){
        return "HATCHBACK";
    } else if(type == CAR_TYPE::SEDAN){
        return "SEDAN";
    } else {
        return "SUV";
    }
}

std::ostream &operator<<(std::ostream &os, const Car &rhs) {
    os << "carType: " <<displayCarEnum(rhs.carType)
       << " carPrice: " << rhs.carPrice
       << " carColour: " << rhs.carColour;
    return os;
}