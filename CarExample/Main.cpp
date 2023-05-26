#include "Car.h"
#include "CarType.h"
#include "functionalities.h"
#include<list>
#include<iostream>


int main(){
    Car *c1= new Car("BMW","07zx",CarType::SUV,15000.f);
    Car *c2= new Car("Audi","99T",CarType::SEDAN,13000.f);
    Car *c3= new Car("Benz","9x9",CarType::SUV,10000.f);

    std::list<Car*> list = {c1,c2,c3};
    float limit= 14000;
    std::cout<<"Insurance amount for "<<c1->getCarBrand()<<" is "<<c1->calculateInsuranceAmount()<<"\n";
    std::cout<<"Highest Insurance Amount is: "<<FindHighestInsurance(list)<<"\n";
    std::cout<<"Count is: "<<FindCountOfGivenType(list,CarType::HATCHBACK,limit)<<"\n";

    for(auto* it: list){
        delete it;
    }
    return 0;
}