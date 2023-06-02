#include "MyCar.h"
#include "function.h"

int main(){
    MyCar *c1= new MyCar("BMW","07zx",MyCarType::SUV,15000.f);
    MyCar *c2= new MyCar("Audi","99T",MyCarType::SEDAN,13000.f);
    MyCar *c3= new MyCar("Benz","9x9",MyCarType::SUV,10000.f);

    std::list<MyCar*> list = {c1,c2,c3};
    float limit= 14000;
    //std::cout<<"Insurance amount for "<<c1->getCarBrand()<<" is "<<c1->calculateInsuranceAmount()<<"\n";
    std::cout<<FindHighestInsurance(list);
    //std::cout<<"Count is: "<<FindCountOfGivenType(list,CarType::HATCHBACK,limit)<<"\n";
    for(auto* it: list){
        delete it;
    }
    return 0;
}