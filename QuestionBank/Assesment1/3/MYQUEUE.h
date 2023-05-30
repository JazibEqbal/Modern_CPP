#ifndef MYQUEUE_H
#define MYQUEUE_H
#include<list>
#include <ostream>

template <typename T>
class MYQUEUE
{
private:
    std::list<T> myQueueValues;             //list of values for queue
    int myQueueSize;                        
    int myQueueCapacity;
public:
    MYQUEUE(const MYQUEUE<T> &obj) = default;
    MYQUEUE() = delete;
    //a constructor that takes reference to standard list of type T
    MYQUEUE(std::list<T> &obj);
    MYQUEUE(int capacity);

    bool isEmpty(){
        return (this->getMyQueueSize() == 0);
    }
    T pushBack(T arg);
    T popFront(T value);

    T const& PeekFront();
    T const& PeekBack();

    int getMyQueueSize() const { return myQueueSize; }
    void setMyQueueSize(int myQueueSize_) { myQueueSize = myQueueSize_; }

    int getMyQueueCapacity() const { return myQueueCapacity; }
    void setMyQueueCapacity(int myQueueCapacity_) { myQueueCapacity = myQueueCapacity_; }

    std::list<T> getMyQueueValues() const { return myQueueValues; }
    void setMyQueueValues(const std::list<T> &myQueueValues_) { myQueueValues = myQueueValues_; }

    template <typename A>
    friend std::ostream &operator<<(std::ostream &os, const MYQUEUE<A> &rhs) {
    os << "myQueueSize: " << rhs.getMyQueueSize()<<"\n"
       << "myQueueCapacity: " << rhs.getMyQueueCapacity()<<"\n"
       << "myQueueValues: \n";
       for(int i=0;i<3;i++){
        os << rhs.myQueueValues[i]<<"\n";
    };
    return os;
}

};

template <typename T>
inline MYQUEUE<T>::MYQUEUE(std::list<T> &elements)
{
    for(int i=0;i<elements.size();i++){
        this->myQueueValues = elements;
        this->myQueueSize++;
    }
}
//creates an empty queue and sets myQueueCapacity to capacity parameter
template <typename T>
inline MYQUEUE<T>::MYQUEUE(int capacity)
{
    MYQUEUE<T> *t;
    t->myQueueCapacity=capacity;
}

template <typename T>
inline T MYQUEUE<T>::pushBack(T arg)
{
    return *(this->myQueueValues.end() + myQueueCapacity++) = arg;  //pushing one element to queue at the end of the list 
}

template <typename T>
inline T MYQUEUE<T>::popFront(T value)
{
    return value = *(this->myQueueValues.begin()--);  //popping out first element
}

template <typename T>
inline T const &MYQUEUE<T>::PeekFront()
{
    return *(this->myQueueValues.begin());      //checking what is the first element in queue
}

template <typename T>
inline T const &MYQUEUE<T>::PeekBack()
{
    return *(this->myQueueValues.end());        //checking what is the last element of queue
}


#endif // MYQUEUE_H
