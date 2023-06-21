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
    data.emplace_back(std::make_shared<CarUnit>("2",2,CAR_UNIT_TYPE::EXTENDED,20.0f,7,6));
    data.emplace_back(std::make_shared<CarUnit>("3",3,CAR_UNIT_TYPE::BASE,50.0f,14,3));

    carUnitPrice(data);

    std::promise<std::string> pr;
    std::future<std::string> input = pr.get_future();
    std::future<CAR_UNIT_TYPE> r1 = std::async(std::launch::async,matchingCarUnitType,std::ref(data),std::ref(input));
    
    std::promise<int> pr2;
    std::future<int> i2 = pr2.get_future();
    std::future<std::vector<int>> r2 = std::async(std::launch::async,capacityAboveThreshold,std::ref(data),std::ref(i2));

    std::string ans;
    std::cin>>ans;
    pr.set_value(ans);    std::this_thread::sleep_for(std::chrono::milliseconds(30));


    int value;
    std::cin>>value;
    pr2.set_value(value);

    r1.get();
    r2.get();

    for (int i = 0; i < 5; i++)
    {
        arr[i] = std::thread(registrationCost,data.front()); 
    }
    for (int i = 0; i < 5; i++)
    {
        arr[i].join();  //calls the function
    }
}