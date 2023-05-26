#include "Functionalities.h"
#include "Vehicle.h"
#include "Car.h"
#include<iostream>
#include "VehicleType.h"
#include<list>
#include<iostream>

float averageVehicleType(std::list<Vehicle*> &obj){
    float avgPrice=0;
    int count=0;
    for(auto *it: obj){
        avgPrice += it->getVehiclePrice();
        count++;
    }
    return (avgPrice/count);
}

void findGivenVehicleType(std::list<Vehicle*> &obj, enum class VehicleType type){
    for(Vehicle* it: obj){
        if(it->getvehicleType() == type){
           std::cout<<*it;
        }
    }
}

int countOfGiventypes(std::list<Vehicle*> &obj, std::list<VehicleType> &type)
{
    int count=0;
    for(Vehicle* it: obj){
        for(VehicleType ty: type){
              if(ty == it->getvehicleType() ){
                count++;
            }
        }
    }
    return count;
}
