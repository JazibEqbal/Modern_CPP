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
    MYQUEUE() = delete;
    MYQUEUE(const MYQUEUE<T> &obj) = default;
    //a constructor that takes reference to standard list of type T
    MYQUEUE(std::list<T> values);
    MYQUEUE(int capacity);
    MYQUEUE(std::list<T> values,int size,int capacity);
    ~MYQUEUE();

    bool isEmpty();
    void pushBack(T arg);
    T popFront();

    T const& PeekFront();
    T const& PeekBack();

    std::list<T> getMyQueueValues() const { return myQueueValues; }
    void setMyQueueValues(const std::list<T> &myQueueValues_) { myQueueValues = myQueueValues_; }

    int getMyQueueSize() const { return myQueueSize; }
    void setMyQueueSize(int myQueueSize_) { myQueueSize = myQueueSize_; }

    int getMyQueueCapacity() const { return myQueueCapacity; }
    void setMyQueueCapacity(int myQueueCapacity_) { myQueueCapacity = myQueueCapacity_; }


    template <typename A>
    friend std::ostream &operator<<(std::ostream &os, const MYQUEUE<A> &rhs) {
    os << "myQueueSize: " << rhs.getMyQueueSize()<<"\n"
       << "myQueueCapacity: " << rhs.getMyQueueCapacity()<<"\n"
       << "myQueueValues: \n";
       for(auto it: rhs.myQueueValues){
        os<<it;
    };
    return os;
}

};

template <typename T>
inline MYQUEUE<T>::MYQUEUE(std::list<T> elements) :myQueueValues{elements} {}
//creates an empty queue and sets myQueueCapacity to capacity parameter
template <typename T>
inline MYQUEUE<T>::MYQUEUE(int capacity)
{
    MYQUEUE<T> *q;
    q->myQueueCapacity=capacity;
}

template <typename T>
inline MYQUEUE<T>::MYQUEUE(std::list<T> values, int size, int capacity)
: myQueueValues{values}, myQueueSize{size}, myQueueCapacity{capacity}{}

template <typename T>
inline MYQUEUE<T>::~MYQUEUE()
{
    std::cout<<"Destructor\n";
}

template <typename T>
inline bool MYQUEUE<T>::isEmpty()
{
    return myQueueValues.empty();
}

template <typename T>
inline void MYQUEUE<T>::pushBack(T arg)
{
    return myQueueValues.push_back(arg);
    //return *(this->myQueueValues.end() + myQueueCapacity++) = arg;  //pushing one element to queue at the end of the list 
}

template <typename T>
inline T MYQUEUE<T>::popFront()
{
    if(myQueueValues.empty()){
        throw std::runtime_error("Queue is empty");
    }
    return myQueueValues.pop_front();
    //return *(this->myQueueValues.begin()--);  //popping out first element
}

template <typename T>
inline T const &MYQUEUE<T>::PeekFront()
{
    return myQueueValues.front();
    //return *(this->myQueueValues.begin());      //checking what is the first element in queue
}

template <typename T>
inline T const &MYQUEUE<T>::PeekBack()
{
    return myQueueValues.back();
    //return *(this->myQueueValues.end());        //checking what is the last element of queue
}


#endif // MYQUEUE_H
