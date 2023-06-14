#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H
#include<iostream>
#include<algorithm>
#include<functional>
#include "Vehicle.h"
#include "VehicleModel.h"
#include "VehicleOwner.h"
#include "Address.h"
#include "ServiceCounter.h"
#include "VehicleServicePackageType.h"
#include "VehicleModelType.h"
#include<list>

extern std::function<void(std::list<ServiceCounter*> &obj,std::string id) > VehicleOwnerDetails;

extern std::function<void(std::list<VehicleOwner*> &obj,std::string name) > displayAdreess;

extern std::function<VEHICLE_SERVICE_PACKAGE_TYPE(std::list<ServiceCounter*> &obj,std::string name) > ShowServicePackage;

extern std::function<VEHICLE_MODEL_TYPE(std::list<ServiceCounter*> &obj,std::string name) > ShowVehicleModelType;

#endif // FUNCTIONALITIES_H
