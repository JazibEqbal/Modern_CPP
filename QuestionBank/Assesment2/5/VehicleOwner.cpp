#include "VehicleOwner.h"

VehicleOwner::VehicleOwner(std::string name, adreessWrapper address, vehicleWrapper service)
    : vechicleOwnerName{name}, vehicleOwnerAddress{address}, vehicleOwnerRegisteredService{service} {}

VehicleOwner::~VehicleOwner()
{
    std::cout<<"Vehicle Owner destroyed\n";
}

std::ostream &operator<<(std::ostream &os, const VehicleOwner &rhs) {
    os << "vechicleOwnerName: " << rhs.vechicleOwnerName
       << " vehicleOwnerAddress: " << rhs.vehicleOwnerAddress
       << " vehicleOwnerRegisteredService: " << rhs.vehicleOwnerRegisteredService;
    return os;
}
