#ifndef CAR_H
#define CAR_H
#include<iostream>
#include "CarType.h"
#include "Vehicle.h"

class Car : public Vehicle
{
private:
    CAR_TYPE carType;  //enum for categorical data
    float carPrice;
    std::string carColour;
public:
    Car() = delete;
    Car(const Car &obj)= default;
    Car(myVariant id,int registration,VEHICLE_TYPE vehicleType, refWrapper plan, CAR_TYPE type,float price,std::string colour);
    ~Car();
    //Getters and setters
    float getCarPrice() const { return carPrice; }
    void setCarPrice(float carPrice_) { carPrice = carPrice_; }

    std::string getCarColour() const { return carColour; }
    void setCarColour(const std::string &carColour_) { carColour = carColour_; }

    CAR_TYPE getCarType() const { return carType; };

    friend std::ostream &operator<<(std::ostream &os, const Car &rhs);
};
//function to display enum
std::string displayCarEnum(CAR_TYPE type);

#endif // CAR_H
