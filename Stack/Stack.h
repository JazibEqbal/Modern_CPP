#ifndef STACK_H
#define STACK_H
#define MAXSIZE 10
#include<stack>

template <typename T>
class Stack
{
private:
    T* data;
    int top=-1;
    int capacity=10;

public:

    //Default Constructor with zero argm
    Stack(){
        this->data = new T[MAXSIZE];
    };

    /*
        This constructor takes a pointer of type T along with a size parameter (integer)
        It must construct a new stack with element upto number "SIZE" copied from the pointer
        location into the data of this object.
    */
    Stack(T* arr,int size);

    //copy constructor to copy data* of the argm into the current obj
    Stack(const Stack<T>& obj)=default;

    //destructor to clear memory 
    ~Stack();

    /*
        push fn takes one argm of type T and adds it to the top position in the array.
        It returns void.
    */

    void push(T arg);

    /*
        Pop fn should return the element at the top position.
        Decrement top by one and return the element popped.
   */
    T pop();

    /*
        current size will be calculated as top value +1
        Return this number from the fn.
    */
    int size(){
        return this->top+1;
    }
    
    /*
        Return the top most element  (By constant Reference)
    */
    const T& peek();

    /*
        isEmpty function should return true if stack is empty else false.
        return (this->size()==0) instead of if else
    */
    bool isEmpty();

    /*
        isFull fn should return true if stack is Full else false.
    */
    bool isFull();

    T stacktop(const std::stack<T>& stack) const {
        return stack.top();
    }

    Stack<T> merge(const Stack<T>& stack1, const Stack<T>& stack2);

};

#include "stackfunction.hpp"
#endif
