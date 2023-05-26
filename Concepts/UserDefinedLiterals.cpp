#include<iostream>

/*
  you can use an integer, float, character or string literal
  with an added suffix to define your own literal
*/

unsigned long long operator ""_M(unsigned long long number) {
    return number *60;
}

int main(){
    std::cout<<10_M<<"\n";
    return 0;
}