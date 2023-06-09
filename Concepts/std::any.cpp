#include<iostream>
#include<any>
#include<algorithm>

int main(){
    std::any data = 10;
    if(data.has_value()){
        try
        {
            auto *ptr = std::any_cast<int*>(&data);
        }
        catch(const std::bad_any_cast &e)  //only resn why this error is coming bcz of bad casting expression
        {
            std::cerr << "casting failed" << '\n';
        }
        
    }
    std::cout<<"Hello\n";
    return 0;
}

// int n1=10;
// void* ptr = &n1;
// char ch='A';
// ptr = &ch;

// std::cout<<(char*) ptr;