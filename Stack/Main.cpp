#include"Stack.h"
#include<iostream>

int main(){
    int arr[5]={10,20,30,40,50};
    //s1 is a stack of integer values
    Stack<int> s1(arr,5);
    int arr2[3] ={70,80,90};
    Stack<int> s2(arr2,3);
    // Stack<std::string> s2;
    // s2.push("Anu");
    Stack<int> stackMerger;
    Stack<int> mergedStack = stackMerger.merge(s1, s2);
    while (!mergedStack.isEmpty()) {
        std::cout << mergedStack.stacktop() << " ";
        mergedStack.pop();
    }
}