#include<iostream>

//int fact(int number) noexcept;

int fact(int number) noexcept(false){
    if(number < 0){
        throw std::runtime_error("Negative value denied");
    } else if(number == 0 || number == 1){
        return 1;
    }else{
        int total = 1;
        for(int i=2;i<= number;i++){
            total += i;
        }
        return total;
    }
}

// if a function doesn't throw any exception then just use keyword noexcept after the function defination. 

//noexcept(false) will throw an error