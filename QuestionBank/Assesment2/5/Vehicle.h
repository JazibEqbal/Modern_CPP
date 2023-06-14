#ifndef VEHICLE_H
#define VEHICLE_H
#include<iostream>
#include "VehicleModel.h"
#include<functional>
#include "VehicleServicePackageType.h"

using wrapper = std::reference_wrapper<VehicleModel*>;

class Vehicle
{
private:
    std::string vehicleId;
    wrapper vehicleModel;
    VEHICLE_SERVICE_PACKAGE_TYPE vehicleServicePackageType;
public:
    Vehicle() = delete;
    Vehicle(const Vehicle &obj) = default;
    Vehicle(std::string id,wrapper model,VEHICLE_SERVICE_PACKAGE_TYPE type);
    ~Vehicle();

    std::string getVehicleId() const { return vehicleId; }
    void setVehicleId(const std::string &vehicleId_) { vehicleId = vehicleId_; }

    wrapper getVehicleModel() const { return vehicleModel; }
    void setVehicleModel(const wrapper &vehicleModel_) { vehicleModel = vehicleModel_; }

    VEHICLE_SERVICE_PACKAGE_TYPE getVehicleServicePackageType() const { return vehicleServicePackageType; }

    friend std::ostream &operator<<(std::ostream &os, const Vehicle &rhs);
};
std::string displayServicePackageType(VEHICLE_SERVICE_PACKAGE_TYPE type);

#endif // VEHICLE_H
