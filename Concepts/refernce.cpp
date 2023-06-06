/*
before modern cpp
    1) a * symbol is either a multiplication operator or it is used with a pointer
    2) && means logical and operation in CPP

since modern cpp
    1) a * symbol is either a multiplication operator or it is used with a pointer
    2) && means
        a) logical and operation in CPP
        b) r value refernce
        c) forward refernces (universal refernces)
*/

#include<iostream>

void magic(int data){

}

void magic_refernce(int &data){
    int temp =1000;
    data = temp;
    std::cout<<data;
}

void magic_pointer_arg(int *ptr){

}

void magic_rvalue_reference(int&& data){

}

int main(){
    int n1=10;
    int n2=100;

    int *ptr = &n1;
    ptr = &n2; //reassigned ptr to n2
    std::cout<<"n1 is:"<<n1<<"\n";   // normal reassignment is not possible...we use std::ref for this to mske it happen
    std::cout<<"n2 is:"<<n2<<"\n";  //no effect on n1 and n2

    int &data = n1; //an integer reference //data is referening to n1
    data = n2;
    std::cout<<"n1 is:"<<n1<<"\n";
    std::cout<<"n2 is:"<<n2<<"\n"; //references cannot be assigned --it does not have its own memory address
    //cannot store references in any conatiner

    magic(n1);    // copied n1 into the magic function local variable data

    //magic_refernce(n1);   //refernce of n1 is passed

    magic_pointer_arg(&n1); // passing through address

    magic_rvalue_reference(10);   // r value reference

    magic(10);  // copy 10 into magic function's local variable data


    return 0;
}