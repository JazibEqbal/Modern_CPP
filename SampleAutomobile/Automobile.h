#ifndef AUTOMOBILE_H
#define AUTOMOBILE_H
#include<iostream>
#include<functional>
#include<variant>
#include "CarCategory.h"

using myVariant = std::variant<int,std::string>;

class Automobile
{
private:
    myVariant serialNumber;
    std::string carModel;
    float carPrice;
    int carSeatCount;
    CAR_CATEGORY carCategory;
public:
    Automobile() = delete;
    Automobile(const Automobile &obj) = default;
    Automobile(Automobile &&obj) = default;
    Automobile(myVariant number,std::string model,float price,int seat,CAR_CATEGORY type);
    ~Automobile();

    myVariant getSerialNumber() const { return serialNumber; }
    void setSerialNumber(const myVariant &serialNumber_) { serialNumber = serialNumber_; }

    std::string getCarModel() const { return carModel; }
    void setCarModel(const std::string &carModel_) { carModel = carModel_; }

    float getCarPrice() const { return carPrice; }
    void setCarPrice(float carPrice_) { carPrice = carPrice_; }

    int getCarSeatCount() const { return carSeatCount; }
    void setCarSeatCount(int carSeatCount_) { carSeatCount = carSeatCount_; }

    CAR_CATEGORY getCarCategory() const {return carCategory;};

    friend std::ostream &operator<<(std::ostream &os, const Automobile &rhs);
};
std::string displayCarCategory(CAR_CATEGORY type);

#endif // AUTOMOBILE_H
