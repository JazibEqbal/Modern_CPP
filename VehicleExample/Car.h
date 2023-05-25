#ifndef CAR_H
#define CAR_H
#include "Vehicle.h"
#include<iostream>

class Car : public Vehicle
{
private:
    std::string carBrand;
public:
    Car() = default;
    Car(const Car &obj) = delete;
    Car(std::string name,enum class VehicleType type, float price, std::string brand);
    ~Car();
    float RtoTax();

    std::string getCarBrand() const { return carBrand; }
    void setCarBrand(const std::string &carBrand_) { carBrand = carBrand_; }

    friend std::ostream &operator<<(std::ostream &os, const Car &rhs);

};

#endif // CAR_H
