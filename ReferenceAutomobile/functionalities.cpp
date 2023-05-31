#include "AutoMobile.h"
#include<functional>
#include "functionalities.h"

void operation(std::list<float> &data,std::function<float(float)> fun){
    for(auto &it: data){
        std::cout<<fun(it)<<"\n";
    }
}