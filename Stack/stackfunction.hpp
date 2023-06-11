#ifndef STACKFUNCTION_HPP
#define STACKFUNCTION_HPP

#include "Stack.h"
#include <iostream>
#include <exception>

template <typename T>
Stack<T>::Stack(T* arr , int size)
{
    if(size > MAXSIZE){

        throw std::runtime_error("Can't do this!");
    }
    this->data = arr; //copy address inside arr into data
    this->capacity = size;
}

template <typename T>
Stack<T>::~Stack()
{
    std::cout<<"Stack object is destroyed\n";
}

template <typename T>
void Stack<T>::push(T arg)
{
     //exception
    if(this->isFull())
        throw std::runtime_error("Stack is Full");

    *(this->data + (++this->top))=arg;
}

template <typename T>
T Stack<T>::pop()
{
    //exception
    if(this->isEmpty())
        throw std::runtime_error("Stack is empty");

    return *(this->data + (this->top--));
}

template <typename T>
const T& Stack<T>::peek()
{
    return *(this->data + this->top);
}

template <typename T>
bool Stack<T>::isEmpty()
{
    return (this->size()==0);
}

template <typename T>
bool Stack<T>::isFull()
{
    return (this->size()==MAXSIZE-1);
}
template<typename T>
Stack<T> merge(const Stack<T>& stack1, const Stack<T>& stack2) {

        Stack<T> mergedStack;
        Stack<T> tempStack = stack1;
        while (!tempStack.isEmpty()) {
            mergedStack.push(tempStack.stacktop());
            tempStack.pop();
        }

        tempStack = stack2;
        while (!tempStack.isEmpty()) {
            mergedStack.push(tempStack.stacktop());
            tempStack.pop();
        }

        return mergedStack;
}

#endif // STACKFUNCTION_HPP
