#include "AutoMobile.h"
#include<iostream>
#include "functionalities.h"

int main(){
    std::list<float> list = {2.3f,10.7f};
    //AutoMobile *a = new AutoMobile("112",list);
    AutoMobile *a = new AutoMobile("112",std::ref(list));
    std::list<float> list2 = {3.6f,10.7f,99.5f};

    a->setAutoMobileReadings(list2);
    //std::cout<<*a<<"\n";
    //std::cout<<list2.front()<<"\n";
    auto square = [](float num) {return num*num; };
    auto cube = [](float num) {return num*num*num; };
    operation(list,cube);
    delete a;
    return 0;
}