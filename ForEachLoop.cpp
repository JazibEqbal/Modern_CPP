#include<iostream>

int arr[5] = {1,2,3,4,5};

void calculateSquare(){
    for(auto it: arr){
        std::cout<<it*it<<"\n";
    }
}

int main(){
    calculateSquare();
    return 0;
}