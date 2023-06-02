#include<iostream>
#include "Employe.h"
#include "functionalities.h"
#include<list>

int main(){
    Employe *e1 = new Employe("1x",57,DEPARTMENT::ADMIN);
    Employe *e2 = new Employe("2x",74,DEPARTMENT::HR);
    Employe *e3 = new Employe("3x",77,DEPARTMENT::ADMIN);

    std::list<Employe*> list = {e1,e2,e3};

    auto res = FindEmployeeAboveThreshold(list,60);
    if(res.has_value()){
        for(auto *it: res.value()){
            std::cout<<*it<<"\n";
        }
    }else {
        std::cout<<"No one above threshold\n";
    }
    //std::cout<<FindCombinedSalary(list)<<"\n";
    auto res2 = FindEmployeeWithGivenId(list,"1x");
    //std::cout<<*res2.value()<<"\n";

    for(auto *it: list){
        delete it;
    }
    return 0;
}

