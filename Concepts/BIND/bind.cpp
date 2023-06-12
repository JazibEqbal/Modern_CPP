#include<iostream>
#include<list>
#include<functional>

using namespace std::placeholders;

void operation2(std::function<int(int)> fn, std::list<int> data)
{
    for (int &val : data)
    {
        std::cout<<fn(val)<<"\n";
    }
}

auto squareOperstion = std::bind(
    operation2, [](int n)
    { return n * n; },
    _1);

auto cubeOperstion = std::bind(
    operation2, [](int n)
    { return n * n * n; },
    _1);

auto first5PositiveIntegerOperation = std::bind(operation2, _1, std::list<int>{1, 2, 3, 4, 5});

auto swapp = std::bind(operation2, _2, _1);

int main(){
    std::list<int> list{1,2,3};
    squareOperstion(list);
    cubeOperstion(list);
}

/*
create a function that takes 2 parameters
a) a function from int to int (a fun thattakes int as argument and returns int)
b) a list of integer numbers

the operation function returns void

bind this function to create partial functions for the following

a) squareoperation that binds a lambda function to compute and return square of integer
   as first parameter
b) cubeoperation that binds a lambda function to compute and return cube of integer
   as first parameter
c) first5PositiveIntegerOperation that binds a standard list of 1 to 5 as second paramter

d) swappedInput that binds second argument as first and vice versa
*/

std::function<void(std::function<int(int)>, std::list<int>)> operation(std::function<int(int)> fn, std::list<int> data)
{
    for (int &val : data)
    {
        fn(val);
    }
}