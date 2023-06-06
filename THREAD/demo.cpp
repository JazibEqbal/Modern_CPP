#include<iostream>
#include<thread>

int square(int n){
    std::this_thread::sleep_for(std::chrono::seconds(4));   //synthetic delay
    return n*n;
}
int cube(int n){
    std::this_thread::sleep_for(std::chrono::seconds(3));
    return n*n*n;
}
int main(){                                                     //thread takes call by value
    // std::cout<<square(3);
    // std::cout<<cube(4);
    std::thread t1(square,10);                                 
    std::thread t2(cube,10);

    t1.join();
    t2.join();
}

//for multithreading concurrency should be possible which means program should have scope of
//context switching