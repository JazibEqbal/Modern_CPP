#include<iostream>
#include<variant>

void calc(std::variant<int,float> data){
    std::visit([](auto arg){ std::cout<<arg *.9<<"\n";},data);
  }

int main(){
    std::variant<int,float> v1{10};
    std::variant<int,float> v2{15.5f};

    calc(v1);
    calc(v2);
}