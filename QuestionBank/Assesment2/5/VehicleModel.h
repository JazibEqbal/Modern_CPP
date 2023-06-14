#ifndef VEHICLEMODEL_H
#define VEHICLEMODEL_H
#include<iostream>
#include "VehicleModelType.h"

class VehicleModel
{
private:
    std::string vehicleModelBrand;
    std::string vehicleModelMarketName;
    std::string vehicleModelBatchNumber;
    VEHICLE_MODEL_TYPE vehicleModelType;
public:
    VehicleModel() = delete;
    VehicleModel(const VehicleModel &obj) = default;
    VehicleModel(std::string brand, std::string marketName, std::string batchNumber, VEHICLE_MODEL_TYPE type);
    ~VehicleModel();

    std::string getVehicleModelBrand() const { return vehicleModelBrand; }
    void setVehicleModelBrand(const std::string &vehicleModelBrand_) { vehicleModelBrand = vehicleModelBrand_; }

    std::string getVehicleModelMarketName() const { return vehicleModelMarketName; }
    void setVehicleModelMarketName(const std::string &vehicleModelMarketName_) { vehicleModelMarketName = vehicleModelMarketName_; }

    std::string getVehicleModelBatchNumber() const { return vehicleModelBatchNumber; }
    void setVehicleModelBatchNumber(const std::string &vehicleModelBatchNumber_) { vehicleModelBatchNumber = vehicleModelBatchNumber_; }

    enum VEHICLE_MODEL_TYPE getVehicleModelType() const {return vehicleModelType;};

    friend std::ostream &operator<<(std::ostream &os, const VehicleModel &rhs);
};
std::string displayVehicleModelType(VEHICLE_MODEL_TYPE type);


#endif // VEHICLEMODEL_H
