#include<iostream>
#include "functionalities.h"
#include "MYQUEUE.h"


int main(){
    std::list<int> arr = {1,2,3};
    MYQUEUE<int> *t1 = new MYQUEUE<int>(arr);
    MYQUEUE<int> *t2 = new MYQUEUE<int>(arr);

    std::cout<<"Element at position is: "<<FindValueAtGivenPosition(t1,1)<<"\n";
    //MakeCombinedQueue(t1,t2);
    //FindCommonQueueElements(t1,t2);
    return 0;
}