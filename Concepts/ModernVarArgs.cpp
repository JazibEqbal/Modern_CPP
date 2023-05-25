#include<iostream>
#include<list>
/*
  sum takes reference to a statement vector of integers as a parameter
  It then prints the arithmetic total of all values inside the vector
*/

void sum(std::list<int> &&data){
    int total =0;
    for(int value: data){
        total +=value;
    }
    std::cout<<total<<"\n";
}

bool checkOdd(std::list<int> &&data){
    for(int value: data){
        if(value % 2 !=0){
            return true;
        }
    }
    return false;
}

int main(){
    sum(std::list<int>{1,2,3,4,5});
    sum(std::list<int>{-10,-20,-30});
    sum(std::list<int>{-20});
    sum(std::list<int>{10,20});
    std::cout<<checkOdd(std::list<int>{12,2,32,4})<<"\n";
}