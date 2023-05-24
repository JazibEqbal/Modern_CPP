#ifndef DATAHOLDER_H
#define DATAHOLDER_H
#include<iostream>
#include<list>

template <typename T>
class DataHolder
{
private:
    std::list<T> dataValues;
public:
    DataHolder() = delete;
    DataHolder(const DataHolder<T> &obj) = default;
    DataHolder(std::list<T> &items);   //DataHolder(std::list<T> &&items); --- rvalue refernce works much fast
    ~DataHolder();
};

template <typename T>
inline DataHolder<T>::DataHolder(std::list<T> &items) : dataValues{items} {}

template <typename T>
inline DataHolder<T>::~DataHolder(){
    std::cout<<"Destructor called\n";
}

#endif // DATAHOLDER_H


/*
  level 1 topics
    lvalues & rvalues
  level 2 topics
    lvalue reference & rvalue reference
  level 3 topics
    move constructor and std::move function
  level 4 topic
    template argument deduction
  level 5 topics
    forward references 
*/