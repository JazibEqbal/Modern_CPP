#ifndef MYCAR_H
#define MYCAR_H
#include<iostream>
#include "MyCarType.h"

class MyCar
{
private:
    std::string carBrand;
    std::string carModel;
    enum class MyCarType myCarType;
    float carPrice;
public:
    MyCar() = delete;
    MyCar(const MyCar &obj) = default;
    MyCar(std::string brand, std::string model);
    MyCar(std::string brand, std::string model,enum class MyCarType type);
    MyCar(std::string brand,std::string model, enum class MyCarType type, float price);
    ~MyCar();

    std::string getMyCarBrand() const { return carBrand; }
    void setCarBrand(const std::string &carBrand_) { carBrand = carBrand_; }

    std::string getCarModel() const { return carModel; }
    void setCarModel(const std::string &carModel_) { carModel = carModel_; }

    float getCarPrice() const { return carPrice; }
    void setCarPrice(float carPrice_) { carPrice = carPrice_; }

    enum class MyCarType getMyCarType() const {return myCarType; }

    friend std::ostream &operator<<(std::ostream &os, const MyCar &rhs);

    float calculateInsuranceAmount();
};
std::string displayEnum(enum class MyCarType type);

#endif // MYCAR_H
