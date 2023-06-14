#include "functionalities.h"

std::function<void(std::list<ServiceCounter*> &obj,std::string id) > VehicleOwnerDetails = [](std::list<ServiceCounter*> &obj,std::string id){
    for(auto &it: obj){
        if(it->getServiceCenterCustomerDetails().get()->getVehicleOwnerRegisteredService().get()->getVehicleId() == id){
            std::cout<<*it;
        }
    }
};

std::function<void(std::list<VehicleOwner*> &obj,std::string name) > displayAdreess = [](std::list<VehicleOwner*> &obj,std::string name){
    std::for_each(obj.begin(),obj.end(),[&](VehicleOwner *v){
        if(v->getVechicleOwnerName() == name){
            std::cout<<v->getVehicleOwnerAddress().get();
        }
    });
};

std::function<VEHICLE_SERVICE_PACKAGE_TYPE(std::list<ServiceCounter*> &obj,std::string name) > ShowServicePackage = 
[](std::list<ServiceCounter*> &obj,std::string name){
    VEHICLE_SERVICE_PACKAGE_TYPE veh;
    std::for_each(obj.begin(),obj.end(),[&](ServiceCounter *v){
        if(v->getServiceCenterName() == name){
           veh = v->getServiceCenterCustomerDetails().get()->getVehicleOwnerRegisteredService().get()->getVehicleServicePackageType();
        }
    });
    return veh;
};

std::function<VEHICLE_MODEL_TYPE(std::list<ServiceCounter*> &obj,std::string name) > ShowVehicleModelType = 
[](std::list<ServiceCounter*> &obj,std::string name){
    VEHICLE_MODEL_TYPE type;
    std::for_each(obj.begin(),obj.end(),[&](ServiceCounter *s){
        if(s->getServiceCenterName() == name){
                type = s->getServiceCenterCustomerDetails().get()->getVehicleOwnerRegisteredService().get()->getVehicleModel().get()->getVehicleModelType();
        }
    });
    return type;
};
