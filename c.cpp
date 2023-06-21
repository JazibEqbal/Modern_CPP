#include <iostream>
#include <thread>

int main(){
    int n1=10;
    auto f1=[](int arg){std::cout << arg;};
    std::thread t1(f1, std::ref(n1)    );
}