#include "ServiceCounter.h"

ServiceCounter::ServiceCounter(std::string name, serviceWrapper details, int request)
    : serviceCenterName{name}, serviceCenterCustomerDetails{details}, serviceCenterCurrentServiceRequest{request} {}

ServiceCounter::~ServiceCounter()
{
    std::cout<<"Service center destroyed\n";
}

std::ostream &operator<<(std::ostream &os, const ServiceCounter &rhs) {
    os << "serviceCenterName: " << rhs.serviceCenterName
       << " serviceCenterCustomerDetails: " << rhs.serviceCenterCustomerDetails
       << " serviceCenterCurrentServiceRequest: " << rhs.serviceCenterCurrentServiceRequest;
    return os;
}
