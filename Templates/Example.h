#ifndef EXAMPLE_H
#define EXAMPLE_H
#include<iostream>

template <typename T, typename U>        //called as meta class
class Example
{
private:
    T resultId;
    U resultCategory;
public:
    Example() =delete;
    Example(const Example<T,U> &obj) = default;
    Example(T id, U category);
    virtual ~Example();

    T getResultId() const { return resultId; }
    void setResultId(const T &resultId_) { resultId = resultId_; }

    U getResultCategory() const { return resultCategory; }
    void setResultCategory(const U &resultCategory_) { resultCategory = resultCategory_; }
};

template <typename T, typename U>
inline Example<T, U>::Example(T id, U category) : resultId{id} , resultCategory{category} {}

template <typename T, typename U>
inline Example<T, U>::~Example()
{
    std::cout<<"Destructor PARENT called!\n";
}
#endif // EXAMPLE_H
