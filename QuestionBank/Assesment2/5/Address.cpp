#include "Address.h"

Address::Address(std::string city, int houseNumber, std::string street, int zip, std::string state)
 : addressCity{city}, addressHouseNumber{houseNumber}, addressStreet{street}, addressZipCode{zip}, addressState{state} {}
 
Address::~Address()
{
    std::cout<<"Address destroyed\n";
}

std::ostream &operator<<(std::ostream &os, const Address &rhs) {
    os << "addressCity: " << rhs.addressCity
       << " addressHouseNumber: " << rhs.addressHouseNumber
       << " addressStreet: " << rhs.addressStreet
       << " addressZipCode: " << rhs.addressZipCode
       << " addressState: " << rhs.addressState;
    return os;
}
