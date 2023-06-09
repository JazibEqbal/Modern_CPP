#include "AutoMobile.h"
#include<iostream>
#include "functionalities.h"
#include<algorithm>


int main(){
    std::list<float> list = {2.3f,10.7f};
    //AutoMobile *a = new AutoMobile("112",list);
    AutoMobile *a = new AutoMobile("112",std::ref(list));  //this syntax
    std::list<float> list2 = {3.6f,10.7f,99.5f};

    a->setAutoMobileReadings(list2);
    //std::cout<<*a<<"\n";
    //std::cout<<list2.front()<<"\n";
    auto square = [](float num) {return num*num; };
    auto cube = [](float num) {return num*num*num; };
    operation(list,cube);

    std::list<float> result;
    //WAYS 1
    std::copy_if(list2.begin(),list2.end(),result.begin(),[] (float reading){return reading <4.5;});
    
    //2 BEST WAY
    std::copy_if(a->getAutoMobileReadings().get().begin(),
    a->getAutoMobileReadings().get().end(),result.begin(),
    [] (float reading){return reading <4.5;});

    //3 old way
    for(const auto &it: a->getAutoMobileReadings().get()){
        if(it < 4.5){
            result.push_back(it);
        }
    }
    delete a;
    return 0;
}

/*
create a function that takes 2 parameters
a) a function from int to int (a fun thattakes int as argument and returns int)
b) a list of integer numbers

the operation function returns void

bind this function to create partial functions for the following

a) squareoperation that binds a lambda function to compute and return square of integer
   as first parameter
b) cubeoperation that binds a lambda function to compute and return cube of integer
   as first parameter
c) first5PositiveIntegerOperation that binds a standard list of 1 to 5 as second paramter

d) swappedInput that binds second argument as first and vice versa
*/

std::function<void(std::function<int(int)>, std::list<int>) > operation(std::function<int(int)> fn, std::list<int> data){
    for(int &val : data){
        fn(val);
    }
}
using namespace std::placeholders;

void operation2(std::function<int(int)> fn, std::list<int> data){
    for(int &val : data){
        fn(val);
    }
}

auto squareOperstion = std::bind(operation2, [](int n){return n*n;},_2);

auto cubeOperstion = std::bind(operation2, [](int n){return n*n*n;},_2);

auto first5PositiveIntegerOperation = std::bind(operation2,_1,std::list<int>{1,2,3,4,5});

auto swapp = std::bind(operation2,_2,_1);
