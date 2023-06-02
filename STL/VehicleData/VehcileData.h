#ifndef VEHCILEDATA_H
#define VEHCILEDATA_H
#include "VehicleType.h"
#include<iostream>

class VehcileData
{
private:
    std::string vehicleId;
    std::string vehicleModel;
    enum class VEHICLE_TYPE vehicleType;
    int fuelTankCapacity;
    float mileage;
public:
    VehcileData() = delete;
    VehcileData(const VehcileData &obj) = default;
    VehcileData(std::string id,std::string model,enum class VEHICLE_TYPE type,int capacity,float mile);
    ~VehcileData();

    std::string getVehicleId() const { return vehicleId; }
    void setVehicleId(const std::string &vehicleId_) { vehicleId = vehicleId_; }

    std::string getVehicleModel() const { return vehicleModel; }
    void setVehicleModel(const std::string &vehicleModel_) { vehicleModel = vehicleModel_; }

    int getFuelTankCapacity() const { return fuelTankCapacity; }
    void setFuelTankCapacity(int fuelTankCapacity_) { fuelTankCapacity = fuelTankCapacity_; }

    float getMileage() const { return mileage; }
    void setMileage(float mileage_) { mileage = mileage_; }

    enum class VEHICLE_TYPE getVehicleType() const {return vehicleType;};

    int operator+(const VehcileData &obj);

    friend std::ostream &operator<<(std::ostream &os, const VehcileData &rhs);
};
std::string displayType(enum class VEHICLE_TYPE type);

#endif // VEHCILEDATA_H
