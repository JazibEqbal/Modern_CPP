#include "VehicleModel.h"

VehicleModel::VehicleModel(std::string brand, std::string marketName, std::string batchNumber, VEHICLE_MODEL_TYPE type)
    : vehicleModelBrand{brand}, vehicleModelMarketName{marketName}, vehicleModelBatchNumber{batchNumber}, vehicleModelType{type} {}

VehicleModel::~VehicleModel(){
    std::cout << "Vehicle Model Destroyed\n";
}

std::ostream &operator<<(std::ostream &os, const VehicleModel &rhs) {
    os << "vehicleModelBrand: " << rhs.vehicleModelBrand
       << " vehicleModelMarketName: " << rhs.vehicleModelMarketName
       << " vehicleModelBatchNumber: " << rhs.vehicleModelBatchNumber
       << " vehicleModelType: " << displayVehicleModelType(rhs.vehicleModelType);
    return os;
}

std::string displayVehicleModelType(VEHICLE_MODEL_TYPE type)
{
    if(type == VEHICLE_MODEL_TYPE::BASE){
        return "BASE";
    } else if(type == VEHICLE_MODEL_TYPE::EXTENDED){
        return "EXTENDED";
    } else if(type == VEHICLE_MODEL_TYPE::TOP_MODEL){
        return "TOP_MODEL";
    }else{
        return "SPORTS";
    }
}
