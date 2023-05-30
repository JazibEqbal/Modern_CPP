#include "MYQUEUE.h"

template<typename T>
int FindValueAtGivenPosition(MYQUEUE<T> *val, int position){
    if(position >= val->getMyQueueSize() || position < 0){   //checking if position is valid or not
        throw std::runtime_error("Invalid");
    }
    if(val->getMyQueueSize() <= 0){                          //checking if queue is empty or not
        throw std::runtime_error("Queue is empty");
    }
    return (val->getMyQueueValues().front() + position);       //going to the first elemnt and adding position to it and returning the value where pointer points now
}

template<typename T>
MYQUEUE<T> MakeCombinedQueue(MYQUEUE<T> *t1, MYQUEUE<T> *t2){
    MYQUEUE<T> *t3;                                                //creating a temporary object to add two objects
    if(t1->getMyQueueSize() <= 0 || t2->getMyQueueSize() <=0 ){   //checking if queue is empty or not
        throw std::runtime_error("Queue is empty");
    }
        int cap = t1->getMyQueueCapacity() + t2->getMyQueueCapacity();
        t3->setMyQueueCapacity(cap); //adding both instance capacity to t3
        int size =  t1->getMyQueueSize() + t2->getMyQueueSize();
        t3->setMyQueueSize(size);
    for(int i=0;i<t3->getMyQueueSize();i++){
            //t3->setMyQueueValues() = t1->getMyQueueValues() + t2->getMyQueueValues();
    }
    return *t3;
}
template<typename T>
MYQUEUE<T> FindCommonQueueElements(MYQUEUE<T> *t1,MYQUEUE<T> *t2){
    MYQUEUE<T> *t3;
    if(t1->getMyQueueSize() <= 0 || t2->getMyQueueSize() <= 0) {  //checking if queue is empty or not
            throw std::runtime_error("Queue is empty");
    }
    for(int i=0;i< t1->getMyQueueCapacity() ; i++){
        for(int j=0; j < t2->getMyQueueCapacity(); j++){
            if(t1->getMyQueueValues() == t2->getMyQueueValues()){
                t3->setMyQueueValues() = t1->getMyQueueValues();
                t3->setMyQueueSize()++;
            }
        }
    }
    return *t3;
}