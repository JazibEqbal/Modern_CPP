#include "Vehicle.h"
#include "Car.h"
#include <iostream>
#include "Functionalities.h"
#include <list>
#include <memory>
#include <future>

VehicleType converToEnum(std::string& type){
    if(type=="COMMERCIAL"){
        return VehicleType::COMMERCIAL;
    }
    else if(type=="PRIVATE"){
        return VehicleType::PRIVATE;
    }
    else {
        return VehicleType::SPECIAL_PURPOSE;
    }
    
}

int main(){
    std::list<std::shared_ptr<Car>> carobjectlist;
    std::shared_ptr<Insurance> i1=std::make_shared<Insurance>("1",1200,InsuranceType::ZERO_DEBT);
    carobjectlist.emplace_back(std::make_shared<Car>(101,2023,VehicleType::COMMERCIAL,std::ref(i1),CarType::HATCHBACK,120000,"Black"));
    carobjectlist.emplace_back(std::make_shared<Car>(102,2023,VehicleType::COMMERCIAL,std::ref(i1),CarType::SEDAN,130000,"Green"));
    carobjectlist.emplace_back(std::make_shared<Car>(103,2023,VehicleType::PRIVATE,std::ref(i1),CarType::SUV,140000,"white"));


//first function                                        
    carsAboveThreshold(carobjectlist,135000);

   

    // second function

    

    std::string str;
    std::cout<<"enter car type from following:\n 1.COMMERCIAL\n2.PRIVATE\n3.SPECIAL_PURPOSE\n";
    std::cin>>str;
    auto data=converToEnum(str); //A FUTURE VALUE use promise instead and run 
   
    std::future<std::optional<std::list<float>>> res= std::async(std::launch::async,returnCarPriceList,std::ref(carobjectlist),data);
  

     // third function
    auto i=returnCarColorContainer(carobjectlist); // make this async also


     //fourth function
   auto avgres= averageInsuranceAmount(carobjectlist);
   std::cout<<avgres;








}