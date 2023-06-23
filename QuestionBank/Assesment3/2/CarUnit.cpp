#include "CarUnit.h"

CarUnit::CarUnit(std::string number, int batch, CAR_UNIT_TYPE unitType, float price, int tankCapacity, int seat)
    : carUnitNumber{number}, carUnitBatch{batch}, carUnitType{unitType}, carUnitCostPrice{price},
      carUnitFuelTankCapacity{tankCapacity}, carUnitSeatCount{seat} {}

CarUnit::~CarUnit()
{
    std::cout << "Car destroyed\n";
}

std::ostream &operator<<(std::ostream &os, const CarUnit &rhs)
{
    os << "carUnitNumber: " << rhs.carUnitNumber
       << " carUnitBatch: " << rhs.carUnitBatch
       << " carUnitType: " << displayCarUnit(rhs.carUnitType)
       << " carUnitCostPrice: " << rhs.carUnitCostPrice
       << " carUnitFuelTankCapacity: " << rhs.carUnitFuelTankCapacity
       << " carUnitSeatCount: " << rhs.carUnitSeatCount;
    return os;
}

// display enum function to display carUnitType
std::string displayCarUnit(CAR_UNIT_TYPE type)
{
    if (type == CAR_UNIT_TYPE::BASE)
    {
        return "BASE";
    }
    else if (type == CAR_UNIT_TYPE::TOP_MODEL)
    {
        return "TOP_MODEL";
    }
    else if (type == CAR_UNIT_TYPE::SPORTS)
    {
        return "SPORTS";
    }
    else
    {
        return "EXTENDED";
    }
}