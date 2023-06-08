#include<iostream>
#include<functional>
#include<list>

void operation(){
    int n=2;
    auto f1 = [](int n) { return n= n*n;};
    std::cout<<f1(n);
    std::cout<<n<<"\n";
}

int main(){
    operation();
    return 0;
}