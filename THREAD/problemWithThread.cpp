#include<iostream>
#include<thread>
#include<mutex>

std::mutex lk;

int balance = 1000;

void withdraw(){
    for(int i=0;i<100;i++){
        std::this_thread::sleep_for(std::chrono::milliseconds(2));
        //lk.lock();
        std::lock_guard<std::mutex> lg(lk);  //lock guard -- no worry of unlocking. -- it releases at the end of scope
        balance -= 10;      //to overcome this deadlock mark the most crucial step as crucial state
        //lk.unlock();
    }
}

void deposit(){
    for(int i=0;i<100;i++){
        std::this_thread::sleep_for(std::chrono::milliseconds(2));
        //when lock is applied by a thread, all other resource are prohibited from accessing the resource inside the lock
        //lk.lock();
        std::lock_guard<std::mutex> lg(lk);
        balance += 10;
        //lk.unlock();
    }
}

int main(){
    std::thread t1(deposit);
    std::thread t2(withdraw);

    t1.join();
    t2.join();

    std::cout<<balance<<"\n";   //deadlock --common resource used by both threads
                                //RAM and ALU memory is different-- they communicate with each other and in the gap 
                                //context switch happens and data is not the same as original;
}

/*how to prevent data race conditions and deadlocks in modern cpp
    a) mutex -- when lock is applied by a thread, all other resource are prohibited from accessing the resource inside the lock
    b) lock_guard
    c) try_lock
    d) recurssive_guard
    e) conditional variables
*/