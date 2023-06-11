#include "MyQueue.h"
#include <list>
#include <iostream>
#include <list>

/*
    1. find value at given posistion with entering position 
        first check wheather position is less than 0 then it will print not correct 
        then check queue is empty or not

    2. combine queue first and then print the values of new queue as shown 

    3. find common elements firstband then print the new queue.
*/

template <typename T>
int FindValueAtGivenPosition(MyQueue<T>& queue,int pos){
    if(pos<0 || queue.getMyQueueSize()==0){
        wthrow std::runtime_error("Position is not correct");
    }
    if(queue.isEmpty()){
        throw std::runtime_error("Queue is empty");
    }
    auto itr=queue.getMyQueueValues().begin();
    std::advance(itr,pos);
    return *itr;
}

template<typename T>
void merge(const MyQueue<T>& other) {
        if (size + other.size > capacity) {
            throw std::overflow_error("Merged queue exceeds capacity");
        }

        int index = other.frontIndex;
        for (int i = 0; i < other.size; i++) {
            enqueue(other.data[index]);
            index = (index + 1) % other.capacity;
        }
    }

template <typename T>
void FindCommonQueueElements(MyQueue<T> &a,MyQueue<T> &b){
    if(a.myQueueValues.empty() || b.myQueueValues.empty()){
        throw std::cout<<"Queue is empty .";
    }
    std::cout<<"\n";
}