#ifndef CAR_H
#define CAR_H
#include<iostream>
#include "CarType.h"

class Car
{
private:
    std::string carBrand;
    std::string carModel;
    enum class CarType carType;
    float carPrice;
public:
    Car() = delete;
    Car(const Car &obj) = default;
    Car(std::string brand, std::string model);
    Car(std::string brand, std::string model,enum class CarType type);
    Car(std::string brand,std::string model, enum class CarType type, float price);
    ~Car();

    std::string getCarBrand() const { return carBrand; }
    void setCarBrand(const std::string &carBrand_) { carBrand = carBrand_; }

    std::string getCarModel() const { return carModel; }
    void setCarModel(const std::string &carModel_) { carModel = carModel_; }

    float getCarPrice() const { return carPrice; }
    void setCarPrice(float carPrice_) { carPrice = carPrice_; }

    enum class CarType getCarType() const {return carType; }

    friend std::ostream &operator<<(std::ostream &os, const Car &rhs);

    float calculateInsuranceAmount();
};
std::string displayEnum(enum class CarType type);


#endif // CAR_H
