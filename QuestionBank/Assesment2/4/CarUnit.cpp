#include "CarUnit.h"
// constructor
CarUnit::CarUnit(std::string number, int batch, CAR_UNIT_TYPE unitType, int tax, CAR_INSTRUCMENT instrument, std::string color, int tankCapacity, int seat)
    : carUnitNumber{number}, carUnitBatch{batch}, carUnitType{unitType}, carUnitTaxPercent{tax},
      carUnitInstrumentClusterType{instrument}, carUnitColor{color}, carUnitSeatCount{seat} {}

// destructor
CarUnit::~CarUnit()
{
    std::cout << "Car Unit Destructor\n";
}

// friend function
std::ostream &operator<<(std::ostream &os, const CarUnit &rhs)
{
    os << "carUnitNumber: " << rhs.carUnitNumber
       << " carUnitBatch: " << rhs.carUnitBatch
       << " carUnitType: " << displayCarUnit(rhs.carUnitType)
       << " carUnitCostPrice: " << rhs.carUnitCostPrice
       << " carUnitTaxPercent: " << rhs.carUnitTaxPercent
       << " carUnitInstrumentClusterType: " << displayInstrument(rhs.carUnitInstrumentClusterType)
       << " carUnitColor: " << rhs.carUnitColor
       << " carUnitFuelTankCapacity: " << rhs.carUnitFuelTankCapacity
       << " carUnitSeatCount: " << rhs.carUnitSeatCount;
    return os;
}
//display enum function to display carUnitType
std::string displayCarUnit(enum class CAR_UNIT_TYPE type)
{
    if (type == CAR_UNIT_TYPE::BASE)
    {
        return "BASE";
    }
    else if (type == CAR_UNIT_TYPE::TOP_MODEL)
    {
        return "TOP_MODEL";
    }
    else
    {
        return "EXTENDED";
    }
}
//display enum function to display carInstrumentType
std::string displayInstrument(enum class CAR_INSTRUCMENT type)
{
    if (type == CAR_INSTRUCMENT::ANALOG)
    {
        return "ANALOG";
    }
    else if (type == CAR_INSTRUCMENT::DIGITAL)
    {
        return "DIGITAL";
    }
    else
    {
        return "HYBRID";
    }
}