#include <iostream>
#include <thread>
#include <list>
#include<mutex>
//pts - pseudo terminal screen

std::mutex lk;

int arr[10];
void square(int n)
{
    std::cout<<std::this_thread::get_id()<<"\n";
    std::lock_guard<std::mutex> lg(lk); 
    for (int i = 0; i < 5; i++)
    {
        std::this_thread::sleep_for(std::chrono::seconds(41)); // synthetic delay
        arr[i] = i * i;
    }
}
void cube(int n)
{
    std::cout<<std::this_thread::get_id()<<"\n";
    std::lock_guard<std::mutex> lg(lk); 
    for (int i = 0; i < 5; i++)
    {
        std::this_thread::sleep_for(std::chrono::seconds(1)); // synthetic delay
        arr[i + 5] = i * i * i;
    }
}

std::list<int> data{1, 2, 3};
int main()
{ // thread takes call by value
    // std::cout<<square(3);
    // std::cout<<cube(4);
    std::thread t1(square, 10); // main itself is a thread
    std::thread t2(cube, 10);
    // lambday way
    std::thread([](int n)
                {std::this_thread::sleep_for(std::chrono::seconds(100)); return n*n*n; },
                data.begin());
    // while we call join from inside any thread,the thread expected to join goes in block state
    // here main requested the join, main is expected to join which means mainthread goes in block state.

    t1.join(); // resume after t1 finishes & join to its output
    t2.join(); // resume after t2 finishes & join to its output
}

// for multithreading concurrency should be possible which means program should have scope of
// context switching -- concurrency

//threads can be ran parallely if it has multiple cores