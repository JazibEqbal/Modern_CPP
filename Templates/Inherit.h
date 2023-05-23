#ifndef INHERIT_H
#define INHERIT_H
#include "Example.h"
#include<iostream>

template<typename T,typename U>
class Inherit : public Example<T,U>
{
private:
    float finalResultPercentage;
public:
    Inherit() = delete;
    Inherit(const Inherit &obj) = default;
    Inherit(T id,U category, float percent);
    ~Inherit();

    float getFinalResultPercentage() const { return finalResultPercentage; }
    void setFinalResultPercentage(float finalResultPercentage_) { finalResultPercentage = finalResultPercentage_; }
};

template <typename T, typename U>
inline Inherit<T, U>::Inherit(T id, U category, float percent) : Example<T,U>(id,category){
    this->finalResultPercentage = percent;
}

template <typename T, typename U>
inline Inherit<T, U>::~Inherit()
{
    std::cout<<"Destructor CHILD called!\n";
}

#endif // INHERIT_H
