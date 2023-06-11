#ifndef MYQUEUE_H
#define MYQUEUE_H

#include <iostream>
#include <list>
#include <unordered_set>

template <typename T>
class MyQueue {
private:
    std::list<T> myQueueValues;
    int myQueueSize=20;
    int myQueueCapacity;

public:
    MyQueue(const std::list<T>& values) : myQueueValues(values) {}

    MyQueue(int capacity) : myQueueSize(0), myQueueCapacity(capacity) {}

    MyQueue(const MyQueue& other) = default;

    MyQueue() = delete;

    bool IsEmpty() const {
        return myQueueSize == 0;
    }

    void PushBack(const T& value) {
        if (myQueueSize == myQueueCapacity) {
            throw std::overflow_error("Queue is full");
        }

        myQueueValues.push_back(value);
        myQueueSize++;
    }

    void PopFront() {
        if (IsEmpty()) {
            throw std::underflow_error("Queue is empty");
        }

        myQueueValues.pop_front();
        myQueueSize--;
    }

    T PeekFront() const {
        if (IsEmpty()) {
            throw std::underflow_error("Queue is empty");
        }

        return myQueueValues.front();
    }

    T PeekBack() const {
        if (IsEmpty()) {
            throw std::underflow_error("Queue is empty");
        }

        return myQueueValues.back();
    }

    T FindValueAtGivenPosition(int position) const {
        if (position < 0 || position >= myQueueSize) {
            throw std::out_of_range("Invalid position");
        }

        auto it = myQueueValues.begin();
        std::advance(it, position);
        return *it;
    }

void Merge(const MyQueue& other) {
    int totalSize = myQueueSize + other.myQueueSize;
    if (totalSize > myQueueCapacity) {
        throw std::overflow_error("Queue capacity exceeded");
    }

    for (const T& value : other.myQueueValues) {
        if (myQueueSize < myQueueCapacity) {
            myQueueValues.push_back(value);
            myQueueSize++;
        } else {
            break;
        }
    }
}

MyQueue FindCommonQueueElements(const MyQueue& queue1, const MyQueue& queue2) const {
        std::unordered_set<T> set1(queue1.myQueueValues.begin(), queue1.myQueueValues.end());
        std::unordered_set<T> commonElements;

        for (const T& value : queue2.myQueueValues) {
            if (set1.count(value) > 0) {
                commonElements.insert(value);
            }
        }

        MyQueue commonQueue(commonElements.size());
        for (const T& value : commonElements) {
            commonQueue.PushBack(value);
        }

        return commonQueue;
    }

    friend std::ostream& operator<<(std::ostream& os, const MyQueue& queue) {
        os << "Queue values: ";
        for (const T& value : queue.myQueueValues) {
            os << value << " ";
        }
        return os;
    }
};


#endif // MYQUEUE_H
