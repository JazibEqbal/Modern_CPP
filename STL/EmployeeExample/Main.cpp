#include<iostream>
#include "Employe.h"
#include "functionalities.h"
#include<list>

int main(){
    Employe *e1 = new Employe("1x",57,DEPARTMENT::ADMIN);
    Employe *e2 = new Employe("2x",74,DEPARTMENT::HR);
    Employe *e3 = new Employe("3x",77,DEPARTMENT::ADMIN);

    std::list<Employe*> list = {e1,e2,e3};

    FindEmployeeAboveThreshold(list,60);
    std::cout<<FindCombinedSalary(list)<<"\n";
    FindEmployeeWithGivenId(list,"1x");

    for(auto *it: list){
        delete it;
    }
    return 0;
}

    // if(res.has_value()){
    //     std::cout<<res.value().size()<<"\n";
    // }else {
    //     std::cout<<"No one above threshold\n";
    // }