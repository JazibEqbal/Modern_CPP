#include "Automobile.h"
#include "CarCategory.h"
#include "functionalities.h"
#include<iostream>
#include<unordered_map>
#include<functional>
#include<algorithm>
#include<variant>
#include<optional>
#include<list>
#include<thread>
#include<memory>

int main(){
    conatiner data;
    createObjects(data);
    std::thread t1(averagePrice,std::ref(data));
    t1.join();

    std::list<std::string> list{"Phase 1","Phase 2"};
    std::thread t2(avgLocationCarPrice,std::ref(data), list);
    t2.join();

    std::thread t3(listABoveThreshold,std::ref(data));
    t3.join();
}