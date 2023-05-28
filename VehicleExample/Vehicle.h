#ifndef VEHICLE_H
#define VEHICLE_H
#include "VehicleType.h"
#include<iostream>

class Vehicle
{
private:
    std::string vehicleName;
    enum class VehicleType vehicleType;
    float vehiclePrice;
public:
    Vehicle() = default;
    Vehicle(const Vehicle &obj) = delete;
    Vehicle(std::string name,enum class VehicleType type, float price);
    virtual ~Vehicle();

    virtual float RtoTax()=0;
    
    std::string getVehicleName() const { return vehicleName; }
    void setVehicleName(const std::string &vehicleName_) { vehicleName = vehicleName_; }

    float getVehiclePrice() const { return vehiclePrice; }
    void setVehiclePrice(float vehiclePrice_) { vehiclePrice = vehiclePrice_; }

    enum class VehicleType getvehicleType() const {return vehicleType; }

    friend std::ostream &operator<<(std::ostream &os, const Vehicle &rhs);
};
std::string displayEnum(enum class VehicleType vehicleType);

#endif // VEHICLE_H
