#ifndef AUTOMOBILE_H
#define AUTOMOBILE_H

#include <iostream>
#include <functional>
#include <algorithm>
#include <thread>
#include <memory>
#include <variant>
#include "CarCategory.h"

using SerialType=std::variant<std::string,int>;

class AutoMobile{
    SerialType carSerialNumber;
    std::string carModel;
    float carPrice;
    int carSeatCount;
    CarCategory carCategory;

public:
    AutoMobile()=delete;
    AutoMobile(const AutoMobile&)=default;
    AutoMobile(SerialType serial,std::string model,float price,int seat,CarCategory category);
    ~AutoMobile();

    CarCategory getCategory(){return carCategory;}

    SerialType getCarSerialNumber() const { return carSerialNumber; }
    void setCarSerialNumber(const SerialType &carSerialNumber_) { carSerialNumber = carSerialNumber_; }

    std::string getCarModel() const { return carModel; }
    void setCarModel(const std::string &carModel_) { carModel = carModel_; }

    float getCarPrice() const { return carPrice; }
    void setCarPrice(float carPrice_) { carPrice = carPrice_; }

    int getCarSeatCount() const { return carSeatCount; }
    void setCarSeatCount(int carSeatCount_) { carSeatCount = carSeatCount_; }

    CarCategory getCarCategory() const { return carCategory; }
    void setCarCategory(const CarCategory &carCategory_) { carCategory = carCategory_; }

    friend std::ostream &operator<<(std::ostream &os, const AutoMobile &rhs);

};

std::string DisplayCategory(CarCategory type);

#endif // AUTOMOBILE_H
