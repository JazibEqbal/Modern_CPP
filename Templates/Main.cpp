#include "Example.h"
#include "Inherit.h"

int main(){
    Inherit<int,std::string> *i1 = new Inherit<int,std::string>(1,"2x",70.9f);
    std::cout<<i1->getResultId()<<"\n";
    std::cout<<i1->getResultCategory()<<"\n";
    std::cout<<i1->getFinalResultPercentage()<<"\n";
    delete i1;
    return 0;
}