/*
    1) every recurssive algorithm should have a base case(a case whose output does not require further recurssive calls)
    2) every recurssive algorithm depends on "divide on conquer"
*/
#include<iostream>
//paramter pack
template<typename T,typename... A> //this is called as VARIADIC TEMPLATES
T add(T arg,A... args){
    return (arg + ...);
}

//base case
// template<typename T>
// T add(T arg1){
//     return arg1;
// }

int main(){
    std::cout<<add<int,int>(1,2,3,4);
}