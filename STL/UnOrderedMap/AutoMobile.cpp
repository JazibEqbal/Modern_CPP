#include "AutoMobile.h"

AutoMobile::AutoMobile(SerialType serial, std::string model, float price, int seat, CarCategory category):carSerialNumber(serial),carModel(model),carPrice(price),carSeatCount(seat),carCategory(category)
{
}

AutoMobile::~AutoMobile(){
    std::cout<<getCarModel()<<" Destroyed\n";
}

std::string DisplayCategory(CarCategory type){
    if(type==CarCategory::HATCHBACK){
        return "HATCHBACK";
    }
    else if(type==CarCategory::SEDAN){
        return "SEDAN";
    }
    return "SUV";
}

std::ostream &operator<<(std::ostream &os, const AutoMobile &rhs) {
    os << "carSerialNumber: ";
    std::visit([](auto&& arg){std::cout<<arg;},rhs.carSerialNumber);
    os << " carModel: " << rhs.carModel
       << " carPrice: " << rhs.carPrice
       << " carSeatCount: " << rhs.carSeatCount
       << " carCategory: " << DisplayCategory(rhs.carCategory)<<"\n";
    return os;
}
