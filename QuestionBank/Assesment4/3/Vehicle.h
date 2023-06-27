#ifndef VEHICLE_H
#define VEHICLE_H
#include "VehicleType.h"
#include<iostream>
#include<memory>
#include<variant>
#include "Insurance.h"

using myVariant = std::variant<int,std::string>; //variant which can either be int or string
using refWrapper = std::reference_wrapper<std::shared_ptr<Insurance>>; //refernce wrapper of Insurance instance of shared ptr

class Vehicle
{
private:
    myVariant vehicleId;
    int vehicleRegistration;
    VEHICLE_TYPE vehiceType;  //enum for categorical data
    refWrapper vehicleInsurancePlan;
public:
    Vehicle() = delete;
    Vehicle(const Vehicle &obj) = default;
    Vehicle(myVariant id,int registration,VEHICLE_TYPE type, refWrapper plan);
    ~Vehicle();

    //Getters and setters
    myVariant getVehicleId() const { return vehicleId; }
    void setVehicleId(const myVariant &vehicleId_) { vehicleId = vehicleId_; }

    int getVehicleRegistration() const { return vehicleRegistration; }
    void setVehicleRegistration(int vehicleRegistration_) { vehicleRegistration = vehicleRegistration_; }

    refWrapper getVehicleInsurancePlan() const { return vehicleInsurancePlan; }
    void setVehicleInsurancePlan(const refWrapper &vehicleInsurancePlan_) { vehicleInsurancePlan = vehicleInsurancePlan_; }

    VEHICLE_TYPE getVehicleType() const { return vehiceType; };

    void setVehiceType(const VEHICLE_TYPE &vehiceType_) { vehiceType = vehiceType_; }

    friend std::ostream &operator<<(std::ostream &os, const Vehicle &rhs);
};
//function to display enum
std::string displayVehicleEnum(VEHICLE_TYPE type);

#endif // VEHICLE_H
