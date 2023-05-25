#include<iostream>

void magic(int n){
   std::cout<<"1"<<"\n";
}
void magic(int* n){
   std::cout<<"2"<<"\n";    
}
void magic(short n){
   std::cout<<"3"<<"\n";
    
}
int main(){

    // int *ptr;  //ptr has a garbage value
    // int *ptr2 = NULL; //initializes pointer as NULL --- NULL an integer with value 0
    // magic(*ptr2);
    // magic(*ptr2);
    // magic(*ptr2);

    //only 1 above is valid
    // nullptr cannot be implicitly converted to an integral type (exception bool type)
    magic(nullptr);

    return 0;
}