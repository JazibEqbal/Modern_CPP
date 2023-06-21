#ifndef CARUNIT_H
#define CARUNIT_H
#include "CarUnitType.h"
#include<iostream>

class CarUnit
{
private:
//data members
    std::string carUnitNumber;
    int carUnitBatch;
    CAR_UNIT_TYPE carUnitType;
    int carUnitCostPrice;
    int carUnitFuelTankCapacity;
    int carUnitSeatCount;
public:
//data members function
    CarUnit() = delete;
    CarUnit(const CarUnit &obj) = default;
    CarUnit(std::string number, int batch,enum class CAR_UNIT_TYPE unitType,int price,int tankCapacity,int seat);
    ~CarUnit();
//getters and setters
    std::string getCarUnitNumber() const { return carUnitNumber; }
    void setCarUnitNumber(const std::string &carUnitNumber_) { carUnitNumber = carUnitNumber_; }

    int getCarUnitBatch() const { return carUnitBatch; }
    void setCarUnitBatch(int carUnitBatch_) { carUnitBatch = carUnitBatch_; }

    int getCarUnitCostPrice() const { return carUnitCostPrice; }
    void setCarUnitCostPrice(int carUnitCostPrice_) { carUnitCostPrice = carUnitCostPrice_; }

    int getCarUnitFuelTankCapacity() const { return carUnitFuelTankCapacity; }
    void setCarUnitFuelTankCapacity(int carUnitFuelTankCapacity_) { carUnitFuelTankCapacity = carUnitFuelTankCapacity_; }

    int getCarUnitSeatCount() const { return carUnitSeatCount; }
    void setCarUnitSeatCount(int carUnitSeatCount_) { carUnitSeatCount = carUnitSeatCount_; }

    enum class CAR_UNIT_TYPE getCarUnitType() const { return carUnitType;};

    friend std::ostream &operator<<(std::ostream &os, const CarUnit &rhs);

};
std::string displayCarUnit(enum class CAR_UNIT_TYPE type);

#endif // CARUNIT_H
