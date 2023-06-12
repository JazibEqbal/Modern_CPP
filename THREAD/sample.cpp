#include <iostream>
#include <thread>
#include <list>
#include <mutex>

int amount = 100;

std::mutex lk;

void fact()
{
    std::list<int> list;
    std::this_thread::sleep_for(std::chrono::microseconds(100));
    int f = 1;
    for (int i = 1; i <= 10; i++)
    {
        std::lock_guard<std::mutex> lg(lk);
        f = f * i;
        list.push_back(f);
    }
    for (auto it : list)
    {
        std::cout << it << "\n";
    }
}

void square()
{
    std::list<int> list2;
    std::this_thread::sleep_for(std::chrono::microseconds(100));
    int square;
    for (int i = 1; i <= 10; i++)
    {
        std::lock_guard<std::mutex> lg(lk);
        square = i * i;
        list2.push_back(square);
    }
    for (auto it : list2)
    {
        std::cout << it << "\n";
    }
};

void twoTimes()
{
    //lk.lock();
    for (int i = 0; i < 100; i++)
    {
        std::this_thread::sleep_for(std::chrono::microseconds(100));
        std::lock_guard<std::mutex> lg(lk);
        amount = 2 * amount;
        //lk.unlock();
    }
};

void half()
{
    //lk.lock();
    for (int i = 0; i < 100; i++)
    {
        std::this_thread::sleep_for(std::chrono::microseconds(100));
        std::lock_guard<std::mutex> lg(lk);
        amount = amount / 2;
       //lk.unlock();
    }
};

int main()
{
    // std::thread t1(&fact);
    // std::thread t2(&square);

    std::thread t3(&twoTimes);
    std::thread t4(&half);

    // t1.join();
    // t2.join();
    t3.join();
    t4.join();

    std::cout << "Amount is: " << amount << "\n";
    return 0;
}
