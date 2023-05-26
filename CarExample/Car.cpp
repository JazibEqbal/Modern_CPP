#include "Car.h"

Car::Car(std::string brand, std::string model) : carBrand{brand} , carModel{model}{}

Car::~Car()
{
    std::cout<<getCarBrand()<<" Car destroyed\n";
}

Car::Car(std::string brand, std::string model, CarType type) : Car(brand,model)
{
    this->carType = type;
}

Car::Car(std::string brand, std::string model, CarType type, float price) :Car(brand,model,type)
{
    this->carPrice = price;
}
std::string displayEnum(enum class CarType type){
    if(type == CarType::SUV){
        return "SUV";
    } else if(type == CarType::SEDAN){
        return"SEDAN";
    } else{
        return "HATCHBACK";
    }
}

float Car::calculateInsuranceAmount()
{
    if(getCarType() == CarType::SUV || getCarType() == CarType::SEDAN){
        return getCarPrice()*0.15;
    } else {
        return getCarPrice() *0.05;
    }
}

std::ostream &operator<<(std::ostream &os, const Car &rhs) {
    os << "carBrand: " << rhs.carBrand<<"\n"
       << " carModel: " << rhs.carModel<<"\n"
       << " carType: " <<displayEnum(rhs.carType)<<"\n"
       << " carPrice: " << rhs.carPrice<<"\n";
    return os;
}
