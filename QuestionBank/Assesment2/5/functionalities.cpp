#include "functionalities.h"

std::function<void(std::list<ServiceCounter *> &obj, std::string id)> VehicleOwnerDetails = [](std::list<ServiceCounter *> &obj, std::string id)
{
    std::for_each(obj.begin(), obj.end(), [&](ServiceCounter *it)
                  {
        if(it->getServiceCenterCustomerDetails().get()->getVehicleOwnerRegisteredService().get()->getVehicleId() == id){
            std::cout<<"Vehicle Owner Details with "<<id<<" are:\n";
            std::cout<<"Vehicle Owner Name: "<<it->getServiceCenterCustomerDetails().get()->getVechicleOwnerName()<<"\n";
            std::cout<<"Vehicle Id: "<<it->getServiceCenterCustomerDetails().get()->getVehicleOwnerRegisteredService().get()->getVehicleId()<<"\n";
            std::cout<<"Vehicle Model: "<<it->getServiceCenterCustomerDetails().get()->getVehicleOwnerRegisteredService().get()->getVehicleModel()<<"\n";
        } });
};

std::function<void(std::list<VehicleOwner *> &obj, std::string name)> displayAdreess = [](std::list<VehicleOwner *> &obj, std::string name)
{
    std::for_each(obj.begin(), obj.end(), [&](VehicleOwner *v)
                  {
        if(v->getVechicleOwnerName() == name){
            std::cout<<"Address of matched Owner with "<<name<<" are: \n";
            std::cout<<"City: "<<v->getVehicleOwnerAddress().get()->getAddressCity()<<"\n";
            std::cout<<"House Number: "<<v->getVehicleOwnerAddress().get()->getAddressHouseNumber()<<"\n";
            std::cout<<"State: "<<v->getVehicleOwnerAddress().get()->getAddressState()<<"\n";
            std::cout<<"Street: "<<v->getVehicleOwnerAddress().get()->getAddressStreet()<<"\n";
            std::cout<<"Zip Code: "<<v->getVehicleOwnerAddress().get()->getAddressZipCode()<<"\n";
        } });
};

std::function<VEHICLE_SERVICE_PACKAGE_TYPE(std::list<ServiceCounter *> &obj, std::string name)> ShowServicePackage =
    [](std::list<ServiceCounter *> &obj, std::string name)
{
    VEHICLE_SERVICE_PACKAGE_TYPE veh;
    std::for_each(obj.begin(), obj.end(), [&](ServiceCounter *v)
                  {
        if(v->getServiceCenterName() == name){
           veh = v->getServiceCenterCustomerDetails().get()->getVehicleOwnerRegisteredService().get()->getVehicleServicePackageType();
        } });
    return veh;
};

std::function<VEHICLE_MODEL_TYPE(std::list<ServiceCounter *> &obj, std::string name)> ShowVehicleModelType =
    [](std::list<ServiceCounter *> &obj, std::string name)
{
    VEHICLE_MODEL_TYPE type;
    std::for_each(obj.begin(), obj.end(), [&](ServiceCounter *s)
                  {
        if(s->getServiceCenterName() == name){
                type = s->getServiceCenterCustomerDetails().get()->getVehicleOwnerRegisteredService().get()->getVehicleModel().get()->getVehicleModelType();
        } });
    return type;
};
