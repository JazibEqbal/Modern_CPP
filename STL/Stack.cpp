#include<iostream>
#include<stack>
#include "AutoMobile.h"
#include<memory>
#include<list>

using Pointer = std::unique_ptr<AutoMobile>;
using container  = std::stack<Pointer>;

int main(){
    std::stack<int> s1;         //stack of integers
    std::stack<AutoMobile> s2;  //stack of Automobile objects
    container s3; //stack of Automobile unique ptrs

    std::stack<Pointer,std::list<Pointer>> s4; //creating stack using list -- by default it is of dequeue 

    s3.emplace(std::make_unique<AutoMobile>());

    
}