#include "VehcileData.h"
#include<list>
#include<functional>
#include<algorithm>
#include<iostream>

auto AverageFuelCapacity = [](std::list<VehcileData*> &v){
    int sum=0;
    int count =0;
    for(auto *it: v){
        sum +=it->getFuelTankCapacity();
        count++;
    }
    return sum/count;
    };

auto FindMileage = [](std::list<VehcileData*> &v){
    std::string id;
    std::cin>>id;
    for(auto *it: v){
        if(it->getVehicleId() == id){
            return it->getMileage();
        }
    }
};

void operation(std::list<VehcileData *> &v,std::list<std::function<float(std::list<VehcileData*> &veh)>> functions){
    for(auto &it: functions){
        std::cout<<it(v)<<"\n";
    }
}


int main(){
    VehcileData *v1 = new VehcileData("1z","URUS",VEHICLE_TYPE::HATCHBACK,20,12.5f);
    VehcileData *v2 = new VehcileData("2z","BMW",VEHICLE_TYPE::SEDAN,10,8.5f);
    VehcileData *v3 = new VehcileData("3z","AUDI",VEHICLE_TYPE::HATCHBACK,12,15.5f);

    std::list<VehcileData*> list = {v1,v2,v3};

    std::list<std::function<float(std::list<VehcileData*> &veh)>> fun = {AverageFuelCapacity,FindMileage};

    std::cout<<AverageFuelCapacity(list)<<"\n";
    std::cout<<FindMileage(list)<<"\n";
    operation(list,fun);
}