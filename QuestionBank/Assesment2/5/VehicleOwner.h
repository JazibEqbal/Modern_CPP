#ifndef VEHICLEOWNER_H
#define VEHICLEOWNER_H
#include<iostream>
#include<functional>
#include "Address.h"
#include "Vehicle.h"

using adreessWrapper = std::reference_wrapper<Address*>;
using vehicleWrapper = std::reference_wrapper<Vehicle*>;

class VehicleOwner
{
private:
    std::string vechicleOwnerName;
    adreessWrapper vehicleOwnerAddress;
    vehicleWrapper vehicleOwnerRegisteredService;
public:
    VehicleOwner() = delete;
    VehicleOwner(const VehicleOwner &obj) = default;
    VehicleOwner(std::string name,adreessWrapper address,vehicleWrapper service);
    ~VehicleOwner();

    std::string getVechicleOwnerName() const { return vechicleOwnerName; }
    void setVechicleOwnerName(const std::string &vechicleOwnerName_) { vechicleOwnerName = vechicleOwnerName_; }

    adreessWrapper getVehicleOwnerAddress() const { return vehicleOwnerAddress; }
    void setVehicleOwnerAddress(const adreessWrapper &vehicleOwnerAddress_) { vehicleOwnerAddress = vehicleOwnerAddress_; }

    vehicleWrapper getVehicleOwnerRegisteredService() const { return vehicleOwnerRegisteredService; }
    void setVehicleOwnerRegisteredService(const vehicleWrapper &vehicleOwnerRegisteredService_) { vehicleOwnerRegisteredService = vehicleOwnerRegisteredService_; }

    friend std::ostream &operator<<(std::ostream &os, const VehicleOwner &rhs);
};

#endif // VEHICLEOWNER_H
