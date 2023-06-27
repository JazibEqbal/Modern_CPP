#include "Manufacture.h"

//user defined constructor
Manufacture::Manufacture(MANUFACTURER_TYPE manufacturer, std::string model, int sale_units, int resale_value, int price, int horsepower)
    : Manufacturer{manufacturer}, Model{model}, Sale_Units{sale_units},
      Resale_Value{resale_value}, Price{price}, Horsepower{horsepower} {}

//destrcutor
Manufacture::~Manufacture()
{
    std::cout<<"Object Destroyed\n";
}

//friend function to display content of a object
std::ostream &operator<<(std::ostream &os, const Manufacture &rhs) {
    os << "Manufacturer: " <<displayManufacturer(rhs.Manufacturer)
       << " Model: " << rhs.Model
       << " Sale_Units: " << rhs.Sale_Units
       << " Resale_Value: " << rhs.Resale_Value
       << " Price: " << rhs.Price
       << " Horsepower: " << rhs.Horsepower;
    return os;
}
std::string displayManufacturer(MANUFACTURER_TYPE type){
    if(type == MANUFACTURER_TYPE::Acura){
        return "Acura";
    }else if(type == MANUFACTURER_TYPE::Audi){
        return "Audi";
    }else if(type == MANUFACTURER_TYPE::BMW){
        return "BMW";
    } else if(type == MANUFACTURER_TYPE::Cadillac){
        return "Cadillac";
    }
    else{
        return "Chevrolet";
    }
}