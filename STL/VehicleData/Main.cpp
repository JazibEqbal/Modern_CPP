#include "VehcileData.h"
#include<list>
#include<functional>
#include<algorithm>
#include<iostream>
#include "functionalities.h"

int main(){
    VehcileData *v1 = new VehcileData("1z","URUS",VEHICLE_TYPE::HATCHBACK,20,12.5f);
    VehcileData *v2 = new VehcileData("2z","BMW",VEHICLE_TYPE::SEDAN,10,8.5f);
    VehcileData *v3 = new VehcileData("3z","AUDI",VEHICLE_TYPE::HATCHBACK,12,15.5f);

    std::list<VehcileData*> list = {v1,v2,v3};

    std::list<std::function<float(std::list<VehcileData*> &veh)>> fun = {AverageFuelCapacity,FindMileage};
    //std::cout<<AverageFuelCapacity(list);

    operation(list,fun);
}