#include<iostream>
#include "PerfectForwarding.h"
#include<memory>

/*RULES for lvalues and rvalues

    Data        Operation     Output
     T&            &&           T&
     T&             &           T&
     T&&            &           T&
     T&&           &&           T&&
*/
//if the object is const which is declared in findTax parameter then you must write "const" keyword after function declaration to access this method

void findTax(const PerfectForwarding &obj){     //accepts l value //it is constant lvalue refernce to Perfect
    std::cout<<"Tax is: "<<obj.calculateSalary()<<"\n";
}
template<typename T>
void Relay(T&& x){
    std::cout<<x<<"\n";
    findTax(std::forward<T&&>(x)); //here it is decided what to send
}

void dummy(const PerfectForwarding &&obj){  //expecting rvalue
    std::cout<<obj.getEmpId()<<"\n";
}

template<typename T>
void RValeRelay(T&& x){
    std::cout<<x<<"\n";
    dummy(std::forward<T&&>(x));
}

int main(){
    std::unique_ptr<PerfectForwarding> ptr = std::make_unique<PerfectForwarding>(100,300.5f);
    PerfectForwarding p(1100,3300.5f);

    //caaling by l value
    Relay<PerfectForwarding&>(*ptr);        //on heap   //T means here PerfectForwarding reference --lvalue     // T& && --> output T&(lvalue)

    Relay<PerfectForwarding&>(p);           //on stack

    //calling by rvalue 
    RValeRelay<PerfectForwarding&&>(PerfectForwarding(1,3.4f)); //passing an rvalue--make sure it is treated as rvalue everywhere it s used-- dummy function
}