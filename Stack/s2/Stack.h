#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <stdexcept>
template<typename T>
class Stack {

private:
    int capacity_;
    int size_;
    T* stack_;
public:
    Stack(int capacity) : capacity_(capacity), size_(0), stack_(new T[capacity]) {}

    ~Stack() {
        delete[] stack_;
    }

    void push(const T& element) {
        if (size_ < capacity_) {
            stack_[size_] = element;
            ++size_;
        } else {
            throw std::runtime_error("Stack is full");
        }
    }

    void pop() {
        if (!isEmpty()) {
            --size_;
        } else {
            throw std::runtime_error("Stack is empty");
        }
    }

    T& top() {
        if (!isEmpty()) {
            return stack_[size_ - 1];
        }
        throw std::runtime_error("Stack is empty");
    }

    const T& top() const {
        if (!isEmpty()) {
            return stack_[size_ - 1];
        }
        throw std::runtime_error("Stack is empty");
    }

    bool isEmpty() const {
        return size_ == 0;
    }

    int size() const {
        return size_;
    }

    void clear() {
        size_ = 0;
    }

    void merge(const Stack<T>& other) {
        int otherSize = other.size();
        if (size_ + otherSize <= capacity_) {
            for (int i = 0; i < otherSize; ++i) {
                stack_[size_ + i] = other.stack_[i];
            }
            size_ += otherSize;
        } else {
            throw std::runtime_error("Stack capacity exceeded");
        }
    }

    void display() const {
        for (int i = 0; i < size_; ++i) {
            std::cout << stack_[i] << " ";
        }
        std::cout << std::endl;
    }

    void findCommonElements(const Stack<T>& other) const {
        for (int i = 0; i < size_; ++i) {
            for (int j = 0; j < other.size(); ++j) {
                if (stack_[i] == other.stack_[j]) {
                    std::cout << stack_[i] << " is a common element" << std::endl;
                    break;
                }
            }
        }
    }

    Stack<T> addStacks(const Stack<T>& other) const {
        int maxSize = size_ > other.size() ? size_ : other.size();
        Stack<T> result(maxSize);
        int i = 0;
        while (i < size_ && i < other.size()) {
            result.push(stack_[i] + other.stack_[i]);
            ++i;
        }
        while (i < size_) {
            result.push(stack_[i]);
            ++i;
        }
        while (i < other.size()) {
            result.push(other.stack_[i]);
            ++i;
        }
        return result;
    }
};

#endif // STACK_H


// template<typename T>
// class Stack {
// private:
//     size_t capacity_;
//     size_t size_;
//     T* stack_;
// public:
//     Stack(size_t capacity) : capacity_(capacity), size_(0), stack_(new T[capacity]) {}

//     ~Stack() {
//         delete[] stack_;
//     }

//     void push(const T& element) {
//         if (size_ < capacity_) {
//             stack_[size_] = element;
//             ++size_;
//         } else {
//             throw std::runtime_error("Stack is full");
//         }
//     }

//     void pop() {
//         if (!isEmpty()) {
//             --size_;
//         } else {
//             throw std::runtime_error("Stack is empty");
//         }
//     }

//     T& top() {
//         if (!isEmpty()) {
//             return stack_[size_ - 1];
//         }
//         throw std::runtime_error("Stack is empty");
//     }

//     const T& top() const {
//         if (!isEmpty()) {
//             return stack_[size_ - 1];
//         }
//         throw std::runtime_error("Stack is empty");
//     }

//     bool isEmpty() const {
//         return size_ == 0;
//     }

//     size_t size() const {
//         return size_;
//     }

//     void clear() {
//         size_ = 0;
//     }

//     void merge(const Stack<T>& other) {
//         size_t otherSize = other.size();
//         if (size_ + otherSize <= capacity_) {
//             for (size_t i = 0; i < otherSize; ++i) {
//                 stack_[size_ + i] = other.stack_[i];
//             }
//             size_ += otherSize;
//         } else {
//             throw std::runtime_error("Stack capacity exceeded");
//         }
//     }

//     void display() const {
//         for (size_t i = 0; i < size_; ++i) {
//             std::cout << stack_[i] << " ";
//         }
//         std::cout << std::endl;
//     }

//     void findCommonElements(const Stack<T>& other) const {
//         for (size_t i = 0; i < size_; ++i) {
//             for (size_t j = 0; j < other.size(); ++j) {
//                 if (stack_[i] == other.stack_[j]) {
//                     std::cout << stack_[i] << " is a common element" << std::endl;
//                     break;
//                 }
//             }
//         }
//     }

//     Stack<T> addStacks(const Stack<T>& other) const {
//         size_t maxSize = size_ > other.size() ? size_ : other.size();
//         Stack<T> result(maxSize);
//         size_t i = 0;
//         while (i < size_ && i < other.size()) {
//             result.push(stack_[i] + other.stack_[i]);
//             ++i;
//         }
//         while (i < size_) {
//             result.push(stack_[i]);
//             ++i;
//         }
//         while (i < other.size()) {
//             result.push(other.stack_[i]);
//             ++i;
//         }
//         return result;
//     }
// };

    // std::stack<T> merge(const std::stack<T>& stack1, const std::stack<T>& stack2) {
    //     std::stack<T> mergedStack;

    //     // Push elements from stack1 to mergedStack
    //     std::stack<T> tempStack = stack1;
    //     while (!tempStack.empty()) {
    //         mergedStack.push(tempStack.top());
    //         tempStack.pop();
    //     }

    //     // Push elements from stack2 to mergedStack
    //     tempStack = stack2;
    //     while (!tempStack.empty()) {
    //         mergedStack.push(tempStack.top());
    //         tempStack.pop();
    //     }

    //     return mergedStack;
    // }