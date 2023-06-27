#ifndef MANUFACTURE_H
#define MANUFACTURE_H
#include<iostream>
#include "ManufacturerType.h"

class Manufacture
{
private:
//Data members
    MANUFACTURER_TYPE Manufacturer;
    std::string Model;
    int Sale_Units;
    int Resale_Value;
    int Price;
    int Horsepower;
//Data member functions
public:
    Manufacture() = delete;     //deleted default constructor
    Manufacture(const Manufacture&) = default;  //defaulted copy constructor
    //user defined constructor
    Manufacture(MANUFACTURER_TYPE manufacturer, std::string model,int sale_units,int resale_value, int price, int horsepower);
    ~Manufacture(); //destrcutor

    //GETTERS AND SETTERS
    MANUFACTURER_TYPE getManufacturer() const { return Manufacturer;};

    std::string model() const { return Model; }
    void setModel(const std::string &model) { Model = model; }

    int saleUnits() const { return Sale_Units; }
    void setSale_Units(int saleUnits) { Sale_Units = saleUnits; }

    int resaleValue() const { return Resale_Value; }
    void setResale_Value(int resaleValue) { Resale_Value = resaleValue; }

    int price() const { return Price; }
    void setPrice(int price) { Price = price; }

    int horsepower() const { return Horsepower; }
    void setHorsepower(int horsepower) { Horsepower = horsepower; }

    //friend function to display content of a object
    friend std::ostream &operator<<(std::ostream &os, const Manufacture &rhs);
};
std::string displayManufacturer(MANUFACTURER_TYPE type);

#endif // MANUFACTURE_H
