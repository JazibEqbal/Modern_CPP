#include <iostream>
#include <algorithm>
#include <functional>
#include "Vehicle.h"
#include "VehicleModel.h"
#include "VehicleOwner.h"
#include "Address.h"
#include "ServiceCounter.h"
#include "VehicleServicePackageType.h"
#include "VehicleModelType.h"
#include <list>
#include "functionalities.h"

int main()
{
    VehicleModel *vehicleModel = new VehicleModel("bsb", "Jahan", "ab887", VEHICLE_MODEL_TYPE::BASE);
    Vehicle *vehicle = new Vehicle("12", std::ref(vehicleModel), VEHICLE_SERVICE_PACKAGE_TYPE::FREE);
    Address *address = new Address("gaya", 22, "abc", 22, "Bihar");
    VehicleOwner *vehicleOwner = new VehicleOwner("BMW", std::ref(address), std::ref(vehicle));
    ServiceCounter *s1 = new ServiceCounter("a", std::ref(vehicleOwner), 6);
    // ServiceCounter *s2 = new ServiceCounter("c",std::ref(vehicleOwner),16);
    // ServiceCounter *s3 = new ServiceCounter("c",std::ref(vehicleOwner),4);
    std::list<VehicleOwner *> list2 = {vehicleOwner};
    std::list<ServiceCounter *> list = {s1};
    // calling functions
    VehicleOwnerDetails(list, "12");
    displayAdreess(list2, "BMW");

    auto binding = std::bind(ShowServicePackage, std::placeholders::_1, "a");
    std::cout << "Vehicle Service Package Type is: " << displayServicePackageType(binding(list)) << "\n";
    std::cout << "Vehicle Model Type is: " << displayVehicleModelType(ShowVehicleModelType(list, "a")) << "\n";
}