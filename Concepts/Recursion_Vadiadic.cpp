/*
    1) every recurssive algorithm should have a base case(a case whose output does not require further recurssive calls)
    2) every recurssive algorithm depends on "divide on conquer"
*/
#include<iostream>
//paramter pack
template<typename T,typename... A> //this is called as VARIADIC TEMPLATES
T add(T arg,A... args){
    return (arg + ... + args); //binary fold
}

template<typename T,typename... A> //this is called as VARIADIC TEMPLATES
T mul(T arg,A... args){
    return (arg * ... * args); //binary fold (fold expression)
}

int main(){
    //This is called as CTAD: template argument expression --add<int,int> removing this
    std::cout<<add(1,2,3,4)<<"\n";
    std::cout<<mul(1,2,3,4)<<"\n";
}

//base case
// template<typename T>
// T add(T arg1){
//     return arg1;
// }