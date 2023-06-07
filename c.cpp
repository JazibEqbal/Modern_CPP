#include<iostream>
#include<functional>
#include<list>


void operation(){
    int n=2;
    auto f1 = [&]() mutable { return n = n*n;};
    f1();
    std::cout<<n<<"\n";
}

int main(){
    operation();
    return 0;
}