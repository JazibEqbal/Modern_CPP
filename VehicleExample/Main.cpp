#include "Car.h"
#include "Vehicle.h"
#include "VehicleType.h"
#include<iostream>
#include<list>
#include "Functionalities.h"

int main(){
    Vehicle *v1 = new Car("A",VehicleType::SUV,34.6f,"BMW");
    Vehicle *v2 = new Car("B",VehicleType::ELECTRIC_SUV,214.6f,"AUDI");
    Vehicle *v3 = new Car("A",VehicleType::ICE_TWO_WHEELER,34.6f,"MERCEDES");
    std::list<Vehicle*> list{v1,v2,v3};
    std::cout<<"Average Price: "<<averageVehicleType(list)<<"\n";
    
    findGivenVehicleType(list,VehicleType::ELECTRIC_SUV);

    //enum class VehicleType type
    //findGivenVehicleType(list,type); //if u want to take input from user
    std::list<VehicleType> l3 = {VehicleType::ELECTRIC_SUV,VehicleType::ELECTRIC_SUV};

    std::cout<<"Count is: "<<countOfGiventypes(list,l3)<<"\n";

    for(auto it: list){
        delete it;
    }
    return 0;
}
