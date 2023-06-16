#include "Automobile.h"

Automobile::Automobile(myVariant number, std::string model, float price, int seat, CAR_CATEGORY type)
    : serialNumber{number}, carModel{model}, carPrice{price}, carSeatCount{seat}, carCategory{type} {}

Automobile::~Automobile()
{
    std::cout << "Automobile destroyed ";
    std::visit([](auto &&arg){std::cout<<arg;},this->serialNumber);
    std::cout<<" is destroyed\n";
}

std::ostream &operator<<(std::ostream &os, const Automobile &rhs)
{
    os << "serialNumber: ";
    std::visit([](auto&& arg)
               { std::cout<< arg; },
               rhs.serialNumber);
    os << " carModel: " << rhs.carModel
       << " carPrice: " << rhs.carPrice
       << " carSeatCount: " << rhs.carSeatCount
       << " carCategory: " << displayCarCategory(rhs.carCategory);
    return os;
}

std::string displayCarCategory(CAR_CATEGORY type)
{
    if (type == CAR_CATEGORY::HATCHBACK)
    {
        return "HATCHBACK";
    }
    else if (type == CAR_CATEGORY::SEDAN)
    {
        return "SEDAN";
    }
    else
    {
        return "SUV";
    }
}