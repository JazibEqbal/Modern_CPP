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
    std::cout<<averageVehicleType(list)<<"\n";
    
    findGivenVehicleType(list,VehicleType::ELECTRIC_SUV);

    //enum class VehicleType type
    //findGivenVehicleType(list,type); //if u want to take input from user
    for(auto it: list){
        delete it;
    }
    // delete v1;
    // delete v2;
    // delete v3;
    return 0;
}
