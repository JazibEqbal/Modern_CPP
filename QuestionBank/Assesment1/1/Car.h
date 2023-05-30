#ifndef CAR_H
#define CAR_H
#include "CarCategory.h"
#include<iostream>

class Car
{
private:
    std::string carChassisNumber;
    std::string carBrand;
    std::string carModel;
    enum class CAR_CATEGORY carCategory;
    float carPrice;
    int carSeatCount;
    int carFuelCapacity;
public:
    Car() = delete;                  // a deleted default constructor
    Car(const Car &obj) = default;   // a defaulted copy constructor

    //a parameterized constructor which takes all data members as argument
    Car(std::string chasNumber, std::string brand,std::string model,float price,enum class CAR_CATEGORY category,int seats,int fuel);
    // a parameterized constructor which takes 4 arguments namely chassisNumber, brand ,model and price
    Car(std::string chasNumber, std::string brand,std::string model,float price);
    
    //Destructor
    ~Car();

    //getters and setters for each data members
    std::string getCarChassisNumber() const { return carChassisNumber; }
    void setCarChassisNumber(const std::string &carChassisNumber_) { carChassisNumber = carChassisNumber_; }

    std::string getCarBrand() const { return carBrand; }
    void setCarBrand(const std::string &carBrand_) { carBrand = carBrand_; }

    std::string getCarModel() const { return carModel; }
    void setCarModel(const std::string &carModel_) { carModel = carModel_; }

    float getCarPrice() const { return carPrice; }
    void setCarPrice(float carPrice_) { carPrice = carPrice_; }

    int getCarSeatCount() const { return carSeatCount; }
    void setCarSeatCount(int carSeatCount_) { carSeatCount = carSeatCount_; }

    int getCarFuelCapacity() const { return carFuelCapacity; }
    void setCarFuelCapacity(int carFuelCapacity_) { carFuelCapacity = carFuelCapacity_; }

    enum class CAR_CATEGORY getCategory() const { return carCategory; };

    //a + operator overload to add price of two car objects
    float operator+(const Car &obj);

    //an overloaded << to display all data of an object
    friend std::ostream &operator<<(std::ostream &os, const Car &rhs);
    
};
//a function to display enum
std::string displayEnum(enum class CAR_CATEGORY category);
#endif // CAR_H

