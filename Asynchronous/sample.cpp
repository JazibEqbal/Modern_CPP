#include<iostream>
#include<future>
#include<thread>
#include<mutex>
/*
    write a program to -
        - a function to add an amount given as user input t a global variable
        a function to substract an amount 10 from balance 100 times, each at a delay of 10 milliseconds
*/
int balance=1000;

std::mutex lk;

void add(std::future<int> &fut){
    std::cout<<"Deposit begins...waiting for user input\n";
    //while thread is waiting for future input,it can still do another work so context switching happens
    //std::cout<<"Enter \n";
    int n = fut.get(); //gets blocked here
    std::cout<<"Input fetched\n"; //this line is displayed after input is fetched
    std::lock_guard lg(lk);
    balance +=n;
}

void sub(){
    std::cout<<"Withdraw begins...!!\n";
    for(int i=0;i<100;i++){
        std::lock_guard lg(lk);
        balance -=10;
    }
}

int main(){

    std::promise<int> pr;
    std::future<int> input = pr.get_future();

    std::future<void> r1 = std::async(std::launch::async, &add,std::ref(input)); //async thread
    std::future<void> r2 = std::async(std::launch::async,&sub);

    std::cout<<"Main thread started\n"; //itself a thread

    int x;
    std::cin>>x;
    pr.set_value(x);
    r1.get();   //blocking main thread to wait for r1 to finish
    std::cout<<"Functions completed\n";
    std::cout<<"Final Balance: "<<balance<<"\n";
}