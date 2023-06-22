#ifndef VEHICLE_H
#define VEHICLE_H
#include <iostream>
#include <variant>
#include "VehicleType.h"
#include "Insurance.h"
#include <memory>

using insuranceptr=std::shared_ptr<Insurance>;
class Vehicle
{
private:
    std::variant<int,std::string> vehicleId;
    int vehicleRegistration;
    VehicleType vehicleType;
    insuranceptr vehicleInsurancePlan;

public:
    Vehicle(/* args */) =default;
    Vehicle(std::variant<int,std::string> Id,
    int Registration,
    VehicleType Type,
    insuranceptr InsurancePlan);
    ~Vehicle() {}

    std::variant<int,std::string> getVehicleId() const { return vehicleId; }
    void setVehicleId(const std::variant<int,std::string> &vehicleId_) { vehicleId = vehicleId_; }

    int getVehicleRegistration() const { return vehicleRegistration; }
    void setVehicleRegistration(int vehicleRegistration_) { vehicleRegistration = vehicleRegistration_; }

    VehicleType getVehicleType() const { return vehicleType; }
    void setVehicleType(const VehicleType &vehicleType_) { vehicleType = vehicleType_; }

    insuranceptr getVehicleInsurancePlan() const { return vehicleInsurancePlan; }
    void setVehicleInsurancePlan(const insuranceptr &vehicleInsurancePlan_) { vehicleInsurancePlan = vehicleInsurancePlan_; }


    friend std::ostream &operator<<(std::ostream &os, const Vehicle &rhs);


};


#endif // VEHICLE_H
