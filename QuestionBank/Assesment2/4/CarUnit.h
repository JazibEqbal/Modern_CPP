#ifndef CARUNIT_H
#define CARUNIT_H
#include<iostream>
#include "CarUnitType.h"
#include "CarInstrucment.h"

class CarUnit
{
private:
//data members
    std::string carUnitNumber;
    int carUnitBatch;
    enum class CAR_UNIT_TYPE carUnitType;
    int carUnitCostPrice;
    float carUnitTaxPercent;
    enum class CAR_INSTRUCMENT carUnitInstrumentClusterType;
    std::string carUnitColor;
    int carUnitFuelTankCapacity;
    int carUnitSeatCount;
public:
//data members function
    CarUnit() = delete;
    CarUnit(const CarUnit &obj) = default;
    CarUnit(std::string number, int batch,enum class CAR_UNIT_TYPE unitType,int tax,enum class CAR_INSTRUCMENT instrument,std::string color, int tankCapacity,int seat);
    ~CarUnit();
//getters and setters
    std::string getCarUnitNumber() const { return carUnitNumber; }
    void setCarUnitNumber(const std::string &carUnitNumber_) { carUnitNumber = carUnitNumber_; }

    int getCarUnitBatch() const { return carUnitBatch; }
    void setCarUnitBatch(int carUnitBatch_) { carUnitBatch = carUnitBatch_; }

    int getCarUnitCostPrice() const { return carUnitCostPrice; }
    void setCarUnitCostPrice(int carUnitCostPrice_) { carUnitCostPrice = carUnitCostPrice_; }

    float getCarUnitTaxPercent() const { return carUnitTaxPercent; }
    void setCarUnitTaxPercent(float carUnitTaxPercent_) { carUnitTaxPercent = carUnitTaxPercent_; }

    std::string getCarUnitColor() const { return carUnitColor; }
    void setCarUnitColor(const std::string &carUnitColor_) { carUnitColor = carUnitColor_; }

    int getCarUnitFuelTankCapacity() const { return carUnitFuelTankCapacity; }
    void setCarUnitFuelTankCapacity(int carUnitFuelTankCapacity_) { carUnitFuelTankCapacity = carUnitFuelTankCapacity_; }

    int getCarUnitSeatCount() const { return carUnitSeatCount; }
    void setCarUnitSeatCount(int carUnitSeatCount_) { carUnitSeatCount = carUnitSeatCount_; }

    enum class CAR_UNIT_TYPE getCarUnitType() const { return carUnitType;};

    enum class CAR_INSTRUCMENT getCarUnitInstrumentType() const {return carUnitInstrumentClusterType;};

    friend std::ostream &operator<<(std::ostream &os, const CarUnit &rhs);
};
std::string displayCarUnit(enum class CAR_UNIT_TYPE type);

std::string displayInstrument(enum class CAR_INSTRUCMENT type);

#endif // CARUNIT_H
