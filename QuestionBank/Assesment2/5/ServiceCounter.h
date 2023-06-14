#ifndef SERVICECOUNTER_H
#define SERVICECOUNTER_H
#include<iostream>
#include<functional>
#include "VehicleOwner.h"

using serviceWrapper= std::reference_wrapper<VehicleOwner*>;

class ServiceCounter
{
private:
    std::string serviceCenterName;
    serviceWrapper serviceCenterCustomerDetails;
    int serviceCenterCurrentServiceRequest;
public:
    ServiceCounter() = delete;
    ServiceCounter(const ServiceCounter &obj) = default;
    ServiceCounter(std::string name, serviceWrapper details,int request);
    ~ServiceCounter();

    std::string getServiceCenterName() const { return serviceCenterName; }
    void setServiceCenterName(const std::string &serviceCenterName_) { serviceCenterName = serviceCenterName_; }

    serviceWrapper getServiceCenterCustomerDetails() const { return serviceCenterCustomerDetails; }
    void setServiceCenterCustomerDetails(const serviceWrapper &serviceCenterCustomerDetails_) { serviceCenterCustomerDetails = serviceCenterCustomerDetails_; }

    int getServiceCenterCurrentServiceRequest() const { return serviceCenterCurrentServiceRequest; }
    void setServiceCenterCurrentServiceRequest(int serviceCenterCurrentServiceRequest_) { serviceCenterCurrentServiceRequest = serviceCenterCurrentServiceRequest_; }

    friend std::ostream &operator<<(std::ostream &os, const ServiceCounter &rhs);
};

#endif // SERVICECOUNTER_H
