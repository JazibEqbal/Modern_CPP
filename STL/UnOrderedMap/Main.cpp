#include <functional>
#include "AutoMobile.h"
#include "CarCategory.h"
#include <algorithm>
#include <iostream>
#include <thread>
#include <list>
#include <unordered_map>
#include "functionalities.h"

using myPointer = std::unique_ptr<AutoMobile>;

using CarPriceList=std::list<myPointer>;

using container=std::unordered_map<std::string,CarPriceList>;

using Variant = std::variant<std::string,int>;

int main(){
    container data;
    std::thread t1(CreateAutomobileObjects,std::ref(data));

    std::thread t2(FindAverageCarPrice,std::ref(data));

    t1.join();
    t2.join();
    // std::list<std::string> key{"Phase 1","Phase 2"};
    // stdthread t3(FindAverageCarPriceOfAllUnits,std::ref(data),key);

    // std::thread t4(FindGreaterThanCarPrice,std::ref(data));

    // t3.join();
}