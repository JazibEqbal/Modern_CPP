#include "Manufacture.h"
#include "functionalities.h"
#include<iostream>
#include<algorithm>
#include<functional>
#include<vector>
#include<unordered_map>
#include<memory>
#include<numeric>
#include<list>

using Pointer = std::shared_ptr<Manufacture>; //shared pointer to object
using Conatiner = std::vector<Pointer>;       //creating vector of pointer objects

int main(){
    Conatiner data;

    createEnteries(data);
    countCarUnits(data,20000);
    // averageOfHorsePower(data);
    // combinedInsuranceCost(data);
    modelOfMaximumHorsePower(data);

    auto res1 = uniqueCarBrands(data);
    if(res1.has_value()){
        for(auto &it: res1.value()){
            std::cout<<displayManufacturer(it);
        }
    }else{
        std::cout<<"No values\n";
    }
    
    auto ans = modelsAboveThreshold(data,35000);
        if(ans.has_value()){
        for(auto &it: ans.value()){
            std::cout<<displayManufacturer(it);
        }
    }else{
        std::cout<<"No values\n";
    }
}