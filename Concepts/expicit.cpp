#include<iostream>

class Problem
{
private:
    int demoId;
public:
   explicit Problem(int id) : demoId{id} {}
    ~Problem() {}
};


void fun(Problem obj){
    std::cout<<"Called\n";
}

int main(){
    Problem d1(10);
    fun(d1);   //perfectly fine
    //fun(10); // converts automatic int to an object type of Problem  ---automatic conversion
    fun(10);   // cannot convert 10 to an object as Constructor with single argument is marked as explicit
               // to remove this mark every single argument constructor explicit
}