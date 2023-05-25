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
    for(Vehicle *it: obj){
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