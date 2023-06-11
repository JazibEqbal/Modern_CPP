#ifndef MYQUEUE_H
#define MYQUEUE_H
#include <iostream>
#include  <list>

template<typename T>
class MyQueue{
    std::list<T> myQueueValues;
    int myQueueSize;
    int myQueueCapacity;

public:
    MyQueue()=delete;
    MyQueue(MyQueue&)=default;
    MyQueue(std::list<T> values);
    MyQueue(int capacity);
    MyQueue(std::list<T> values,int size,int capacity);
    ~MyQueue();

    bool isEmpty();
    void pushBack(T element);
    T popFront();
    T peekFront();
    T peekBack();

    int getMyQueueSize() const { return myQueueSize; }
    void setMyQueueSize(int myQueueSize_) { myQueueSize = myQueueSize_; }

    int getMyQueueCapacity() const { return myQueueCapacity; }
    void setMyQueueCapacity(int myQueueCapacity_) { myQueueCapacity = myQueueCapacity_; }

    std::list<T> getMyQueueValues() const { return myQueueValues; }
    void setMyQueueValues(const std::list<T> &myQueueValues_) { myQueueValues = myQueueValues_; }

    template<typename A>
    friend std::ostream &operator<<(std::ostream &os, const MyQueue<A> &rhs);
};


template <typename T>
inline MyQueue<T>::MyQueue(std::list<T> values) : myQueueValues(values)
{
}

template <typename T>
inline MyQueue<T>::MyQueue(int capacity) :myQueueCapacity(capacity)
{
    MyQueue *q1;
    q1->setMyQueueCapacity(capacity);
}

template <typename T>
inline MyQueue<T>::MyQueue(std::list<T> values,int size, int capacity) : myQueueValues(values),myQueueSize(size),myQueueCapacity(capacity)
{
}

template <typename T>
inline MyQueue<T>::~MyQueue()
{
    std::cout<<"Destroyed Queue\n";
}

// CREATE ISEMPTY FUNCTION TO CHECK IF QUEUE IS EMPTY OR NOT

template <typename T>
inline bool MyQueue<T>::isEmpty()
{
    return myQueueValues.empty();
}

// PUSH AT THE BACK OF QUEUE

template <typename T>
inline void MyQueue<T>::pushBack(T element)
{
    myQueueValues.push_back(element);
}
// REMOVE ELEMENT FROM FRONT
template <typename T>
inline T MyQueue<T>::popFront()
{
        if(myQueueValues.empty()){
        throw std::runtime_error("Queue is empty \n");
    }
    return myQueueValues.pop_front();
}

// PRINT FIRST ELEMENET FROM FRONT

template <typename T>
inline T MyQueue<T>::peekFront()
{
    return myQueueValues.front();
}

// PRINT LAST FIRST ELEMENT FROM BACK

template <typename T>
inline T MyQueue<T>::peekBack()
{
    return myQueueValues.back();
}

// DISPLAY QUEUE DATA

template<typename T>
inline std::ostream &operator<<(std::ostream &os, const MyQueue<T> &rhs) {
    for(auto a:rhs.myQueueValues){
        os<<a;
    }
    // os << "myQueueValues: " << rhs.myQueueValues;
    return os;
}

#endif // MYQUEUE_H