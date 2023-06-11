#include <iostream>
#include <functional>
#include <list>
using namespace std::placeholders;

int product(int x, int y = 100)
{
    return x * y;
}
// bind way
int formula(int x, int y, int z, int a)
{
    return ((x - y) * 2 / a);
}
// USE CASE with lambda
auto fn1 = [](int num)
{ return num * num; };
auto fn2 = [](int num, int factor)
{ return num * factor; };

int main()
{
    auto f1 = product(20);
    auto f2 = std::bind(&formula, _1, _2, 10, 100); // z and are fixed

    // USE CASE
    // don't use & with lambda when passing
    auto fn3 = std::bind(fn2, _1, 4); // factor fixed to 4
    fn3(10);
    // creating a function wrapper
    std::vector<std::function<int(int)>> v1 = {fn1, fn3};

    std::cout << f1 << "\n";
    // in class
    bindDemo obj;
    auto ans = std::bind(&bindDemo::magic, &obj, 100, 2);
}
// remap
int fun(int x, int y, int z)
{
    return (x + y) - z;
}

// using std::bind remap
auto ans = std::bind(&fun, _3, _2, _1); // passing 3 arument as 1st argument to user and vice versa

/*you can bind an existing functions's parameter to a value so that it can be
  stored in a container of which expected types does not match with a function to be stored.(ref,fn1&fn3);

  you can remap the order of arguments of an existing function
*/

class bindDemo
{
private:
    /* data */
public:
    bindDemo() = default;
    int magic(int x, int y)
    {
        return x * y;
    }
    ~bindDemo(){};
};

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

void operation2(std::function<int(int)> fn, std::list<int> data)
{
    for (int &val : data)
    {
        fn(val);
    }
}

auto squareOperstion = std::bind(
    operation2, [](int n)
    { return n * n; },
    _2);

auto cubeOperstion = std::bind(
    operation2, [](int n)
    { return n * n * n; },
    _2);

auto first5PositiveIntegerOperation = std::bind(operation2, _1, std::list<int>{1, 2, 3, 4, 5});

auto swapp = std::bind(operation2, _2, _1);