#include<iostream>

class Demo final  //no other class can inherit Demo class as it is marked as final
{
private:
    /* data */
public:
    Demo (/* args */) {}
    ~Demo () {}
}; 

// class InheritMe : Demo   //throws error as parent class is final
// {
// private:
//     /* data */
// public:
//     InheritMe(/* args */) {}
//     ~InheritMe() {}
// };