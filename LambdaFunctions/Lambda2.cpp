#include<iostream>
#include<list>
#include<functional>

//function is a wrapper
void operation(std::list<int> &data, std::function<void(int)> fun){ //void -- return type int --data type
    for(auto &val: data){
        fun(val);
    }
}

int main(){
    std::list<int> data = {1,2,3,4};
    auto fSquare = [](int num){std::cout<<num*num<<"\n";}; //lambda fun being declared and assigned to a variable
    operation(data,fSquare);                               // we are passing lamda variable as parameter
    operation(data, [] (int n){std::cout<<n*100<<"\n";});  //declaring lamdba inline (temporary value and passing it immediately) 
    return 0;
}

//The type of lambda function is same as the signature
//lambda is a rvalue...it's temporary as it is not assigned to any variable
//void (*ptr)(int) = &square;         // pointer to a function square
// void operation(std::list<int> &data, void(*fun)(int)){ //FUNCTION POINTER DECLARATION
//     for(auto &val: data){
//         fun(val);
//     }
// }
//void (*ptr2)(int) = &times;
//operation(data,ptr2);