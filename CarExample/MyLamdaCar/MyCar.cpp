#include "MyCar.h"

MyCar::MyCar(std::string brand, std::string model) : carBrand{brand} , carModel{model}{}

MyCar::~MyCar()
{
    std::cout<<getMyCarBrand()<<" MyCar destroyed\n";
}

MyCar::MyCar(std::string brand, std::string model, MyCarType type) : MyCar(brand,model)
{
    this->myCarType = type;
}

MyCar::MyCar(std::string brand, std::string model, MyCarType type, float price) :MyCar(brand,model,type)
{
    this->carPrice = price;
}
std::string displayEnum(enum class MyCarType type){
    if(type == MyCarType::SUV){
        return "SUV";
    } else if(type == MyCarType::SEDAN){
        return"SEDAN";
    } else{
        return "HATCHBACK";
    }
}

float MyCar::calculateInsuranceAmount()
{
    if(getMyCarType() == MyCarType::SUV || getMyCarType() == MyCarType::SEDAN){
        return getCarPrice()*0.15;
    } else {
        return getCarPrice() *0.05;
    }
}

std::ostream &operator<<(std::ostream &os, const MyCar &rhs) {
    os << "MyCarBrand: " << rhs.carBrand<<"\n"
       << " MyCarModel: " << rhs.carModel<<"\n"
       << " MyCarType: " <<displayEnum(rhs.myCarType)<<"\n"
       << " MyCarPrice: " << rhs.carPrice<<"\n";
    return os;
}
