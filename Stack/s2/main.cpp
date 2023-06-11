#include<iostream>
#include "Stack.h"

int main() {
    Stack<int> stack1(6);
    stack1.push(1);
    stack1.push(2);
    stack1.push(3);

    Stack<int> stack2(3);
    stack2.push(4);
    stack2.push(5);
    stack2.push(6);

    stack1.merge(stack2);

    std::cout << "Merged Stack Top: " << stack1.top() << std::endl;
    std::cout << "Is Merged Stack Empty? " << (stack1.isEmpty() ? "Yes" : "No") << std::endl;
    std::cout << "Merged Stack Size: " << stack1.size() << std::endl;

    stack1.pop();
    std::cout << "After Pop, Merged Stack Top: " << stack1.top() << std::endl;

    stack1.clear();
    std::cout << "After Clear, Is Merged Stack Empty? " << (stack1.isEmpty() ? "Yes" : "No") << std::endl;
    stack2.display();

    return 0;
}

    // try {
    //     int element = stack1.find(2);
    //     std::cout << "Element at position 2: " << element << std::endl;
    // } catch (const std::out_of_range& e) {
    //     std::cout << "Exception: " << e.what() << std::endl;
    // }