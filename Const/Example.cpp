#include<iostream>

/*
    rule 1: const gets applied to whatever is on the left of it.
          If there is nothing on the left, apply it to the token on the right;
    rule 2: If the statement/expression has a * symbol,break down the statement on * and then apply rule 1.
  
*/

int main(){
    const int n1 = 10;  //n1 is a constant integer
    n1=100;   //throws error --- constant can not be modified

    int const n1 = 10;   //n1 is a constant integer

    //------------------------------
    int data=100;
    int v2=10;
    const int * ptr = &data;   //ptr is a pointer to a constant integer
    *ptr = 200;   //cannot modify the value 
    ptr = &v2;    //can modify the address

    //---------------------------------------
    int * const ptr1 = &data;   //ptr1 is a constant ptr to an integer  
    *ptr1 = 200;   //can modify the value
     ptr2 = &v2;   //cannot modify the address

    const int * const ptr3 = &data;   //ptr3 is a constant integer pointer to a constant integer 
    //cannot modify value as well as address
    

    std::cout<<*ptr;   //prints value
    std::cout<<ptr;    //prints address
}