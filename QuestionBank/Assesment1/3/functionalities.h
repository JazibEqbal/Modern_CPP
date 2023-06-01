#include "MYQUEUE.h"

template<typename T>
int FindValueAtGivenPosition(MYQUEUE<T> *val, int position){
    if(position >= val->getMyQueueSize() || position < 0){   //checking if position is valid or not
        throw std::runtime_error("Invalid");
    }
    if(val->getMyQueueSize() == 0){                          //checking if queue is empty or not
        throw std::invalid_argument("Queue is empty");
    }
    return (val->getMyQueueValues().front() + position);       //going to the first elemnt and adding position to it and returning the value where pointer points now
}

template<typename T>
MYQUEUE<T> MakeCombinedQueue(MYQUEUE<T> *q1, MYQUEUE<T> *q2){
    if(q1.getMyQueueValues().empty() || q2.getMyQueueValues().empty()){
        throw std::runtime_error("Queue is empty");
    }
    std::list<T> data;
    for(auto &val: q1){
        data.push_back(val);
        //data.size()++;
    }
    for(auto &val: q2){
        data.push_back(val);
        //data.size()++;
    }

    MYQUEUE<T> *q3;
    for(auto &it: data){
        q3-> pushBack(it);
    }
    return *q3;
}


template<typename T>
MYQUEUE<T> FindCommonQueueElements(MYQUEUE<T> &q1,MYQUEUE<T> &q2){
    if(q1.getMyQueueValues().empty() || q2.getMyQueueValues().empty()){
        throw std::runtime_error("Queue is empty");
    }
}