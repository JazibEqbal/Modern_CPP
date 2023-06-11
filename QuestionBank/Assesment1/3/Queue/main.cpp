#include <iostream>
#include "MyQueue.h"
#include "functionalities.h"

int main(){
    std::list<int> l1;
    std::list<int> l2;
    MyQueue<int>* q1=new MyQueue<int>(l1,5,50);
    MyQueue<int>* q2=new MyQueue<int>(l2,5,50);
    q1->pushBack(3);
    q1->pushBack(5);
    q1->pushBack(6);
    q1->pushBack(4);
    q1->pushBack(10);
    q1->pushBack(7);
    // std::cout<<q1->peekFront()<<"\n";
    // std::cout<<q1->peekBack()<<"\n";
    std::cout<<FindValueAtGivenPosition(*q1,4)<<"\n";
    // std::cout<<MakeCombinedQueue(*q1,*q2);
    // std::cout<<FindCommonQueueElements(q1,q2);
    delete q1;
    delete q2;
}