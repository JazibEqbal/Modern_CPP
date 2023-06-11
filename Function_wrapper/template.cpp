#include <functional>
#include <iostream>

template <typename T>
T add(T x, T y)
{
    return x + y;
}

template <typename T>
T minus(T x, T y)
{
    return x - y;
}

template <typename T>
T runBinaryFunction(T x, T y, std::function<T(T, T)> f)
{
    return f(x, y);
}

template <class T>
class Add
{
public:
    T operator() (T x, T y) const 
    {
        return x + y;
    }
};

template <class T>
class Calculator
{
public:
    static T add(T x, T y)
    {
        return x + y;
    }
};

template <class T>
class Increase
{
public:
    Increase(T val) : mVal{val}
    {
    }
    T increase(T x) const
    {
        return x + this->mVal;
    }
private:
    T mVal;
};

int main()
{
    int x = 1;
    int y = 2;

    // Wrap functions
    std::function<int(int, int)> f1 = add<int>;
    std::cout << f1(x, y) << std::endl;
    std::cout << runBinaryFunction(x, y, f1) << std::endl;

    // Wrap functors
    std::function<int(int, int)> f2 = Add<int>();
    std::cout << f2(x, y) << std::endl;
    std::cout << runBinaryFunction(x, y, f2) << std::endl;

    // Wrap lambda expressions
    std::function<int(int, int)> f3 = [](int x,int y)->int{return x + y;};
    std::cout << f3(x, y) << std::endl;
    std::cout << runBinaryFunction(x, y, f3) << std::endl;

    // Wrap class methods
    std::function<int(int, int)> f4 = std::bind(&Calculator<int>::add, std::placeholders::_1, std::placeholders::_2);
    std::cout << f4(x, y) << std::endl;
    std::cout << runBinaryFunction(x, y, f4) << std::endl;

    Increase<int> increaseTen(10);
    std::function<int(int)> f5 = std::bind(&Increase<int>::increase, increaseTen, std::placeholders::_1);
    std::cout << f5(x) << std::endl;
}