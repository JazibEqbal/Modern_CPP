#include "AutoMobile.h"
#include<iostream>
#include "functionalities.h"
#include<algorithm>


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