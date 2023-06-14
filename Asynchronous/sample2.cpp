#include <iostream>
#include <future>
#include <thread>
#include <mutex>

std::mutex mt;
/*
    write a program to create 100 threads
    Each threads should call a function increment
    Increment should return number incremented by 1 where number is globalset to 1
*/
int number = 1;

void increment()
{
    number++;
}
// no thread creation by async as the next step is to join the thread so it only has to wait
int main()
{
    auto f = []()
    {std::lock_guard lg(mt); number++; };
    std::thread arr[100]; // arr is an array of 100 defaulted constructed threads in contagious memory location.
    for (int i = 0; i < 100; i++)
    {
        arr[i] = std::thread(f); // a call to a constructor returns temporary
    }
    for (int i = 0; i < 100; i++)
    {
        arr[i].join();  //calls the function
    }
    std::cout << "Output is: " << number << "\n";
}