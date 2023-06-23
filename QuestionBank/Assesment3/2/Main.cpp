#include "functionalities.h"
#include "CarUnit.h"
#include "CarUnitType.h"
#include<iostream>
#include<optional>
#include<functional>
#include<algorithm>
#include<list>
#include<vector>
#include<memory>
#include<future>
#include<thread>
#include<array>

using mypointer = std::shared_ptr<CarUnit>;
using container  = std::vector<mypointer>;

std::thread arr[5]; 

int main(){
    container data;
    data.emplace_back(std::make_shared<CarUnit>("1",1,CAR_UNIT_TYPE::BASE,50.0f,12,6));
    data.emplace_back(std::make_shared<CarUnit>("2",2,CAR_UNIT_TYPE::EXTENDED,20.0f,70,8));
    data.emplace_back(std::make_shared<CarUnit>("3",3,CAR_UNIT_TYPE::BASE,10.0f,1400,7));
    data.emplace_back(std::make_shared<CarUnit>("4",4,CAR_UNIT_TYPE::BASE,50.0f,14,3));

    auto res = carUnitPrice(data);
    if(res.has_value()){
        for(auto &it: res.value()){
            std::cout <<"Tax is: "<< it<<"\n";
        }
    }else{
        std::cout<<"something went wrong...\n";
    }

    std::promise<std::string> pr;
    std::future<std::string> input = pr.get_future();
    std::future<void> r1 = std::async(std::launch::async,matchingCarUnitType,std::ref(data),std::ref(input));
    
    std::string ans;
    std::cin>>ans;
    pr.set_value(ans);

    std::promise<float> pr2;
    std::future<float> i2 = pr2.get_future();
    std::future<void> r2 = std::async(std::launch::async,capacityAboveThreshold,std::ref(data),std::ref(i2));

    float value;
    std::cin>>value;
    pr2.set_value(value);

    r1.get();
    r2.get();

    mypointer p = std::make_shared<CarUnit>("1",1,CAR_UNIT_TYPE::BASE,50.0f,12,6);
    for(int i=0;i<5;i++){
        arr[i] = std::thread(registrationCost,std::ref(p));
    }
    for (int i = 0; i < 5; i++)
    {
        arr[i].join();  //calls the function
    }

    // auto res2 = allMatchingInstanceOfCar(50.0f,data);
    // for (auto &it : res2)
    // {
    //     std::cout <<"Satisfied Car Units are: "<< *it<<"\n";
    // }

    std::promise<float> pr3;
    std::future<float> i3 = pr3.get_future();
    std::future<void> r3 = std::async(std::launch::async,allMatchingInstanceOfCar,std::ref(i3),std::ref(data));

    float price;
    std::cin>>price;
    pr3.set_value(price);
    r3.get();
}