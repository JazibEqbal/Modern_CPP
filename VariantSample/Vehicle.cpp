#include "Vehicle.h"

Vehicle::Vehicle(std::string id, float price) : vehicleId{id}, vehiclePrice{price} {}

Vehicle::~Vehicle()
{
    std::cout<<"Vehicle Destroyed\n";
}

std::ostream &operator<<(std::ostream &os, const Vehicle &rhs) {
    os << "vehicleId: " << rhs.vehicleId
       << " vehiclePrice: " << rhs.vehiclePrice;
    return os;
}
