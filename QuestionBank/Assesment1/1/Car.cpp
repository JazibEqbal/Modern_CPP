#include "Car.h"

//using delegation constructor
Car::Car(std::string chasNumber, std::string brand, std::string model, float price, CAR_CATEGORY category, int seats, int fuel)
  : Car(chasNumber,brand,model,price)
{
    this->carCategory = category;
    this->carSeatCount = seats;
    this->carFuelCapacity =fuel;
}

//a constructor with 4 arguments
Car::Car(std::string chasNumber, std::string brand, std::string model, float price)
    : carChassisNumber{chasNumber}, carBrand{brand}, carModel{model}, carPrice{price} {}

//destructor
Car::~Car()
{
    std::cout<<"Car destroyed\n";
}

std::ostream &operator<<(std::ostream &os, const Car &rhs) {
    os << "carChassisNumber: " << rhs.carChassisNumber<<"\n"
       << " carBrand: " << rhs.carBrand<<"\n"
       << " carModel: " << rhs.carModel<<"\n"
       << " carCategory: " <<displayEnum(rhs.carCategory)<<"\n"
       << " carPrice: " << rhs.carPrice<<"\n"
       << " carSeatCount: " << rhs.carSeatCount<<"\n"
       << " carFuelCapacity: " << rhs.carFuelCapacity<<"\n";
    return os;
}
//overloading + operator to calculate sum of two carPrice
float Car::operator+(const Car &obj)
{
    carPrice = carPrice + obj.carPrice;
    return carPrice;
}
//a function to display enum 
std::string displayEnum(enum class CAR_CATEGORY category){
    if(category == CAR_CATEGORY::SEDAN){
        return "SEDAN";
    } else if(category == CAR_CATEGORY::SUV){
        return "SUV";
    } else {
        return "HATCHBACK";
    }
}
