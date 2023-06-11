#include<iostream>
#include "MyQueue.h"
#include<list>

int main() {
    // Create a MyQueue object using a list of values
    std::list<int> values = {1, 2, 3, 4, 5};
    MyQueue<int> queue(values);

    // Display the contents of the queue
    std::cout << "Queue: " << queue << std::endl;

    // Check if the queue is empty
    std::cout << "Is queue empty? " << (queue.IsEmpty() ? "Yes" : "No") << std::endl;

    // Push a value to the back of the queue
    int newValue = 6;
    queue.PushBack(newValue);
    std::cout << "After pushing " << newValue << ", queue: " << queue << std::endl;

    // Pop a value from the front of the queue
    queue.PopFront();
    std::cout << "After popping, queue: " << queue << std::endl;

    // Peek at the front and back elements of the queue
    std::cout << "Front element of the queue: " << queue.PeekFront() << std::endl;
    std::cout << "Back element of the queue: " << queue.PeekBack() << std::endl;

    // Find the value at a given position in the queue
    int position = 2;
    try {
        int valueAtPosition = queue.FindValueAtGivenPosition(position);
        std::cout << "Value at position " << position << " in the queue: " << valueAtPosition << std::endl;
    } catch (const std::out_of_range& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    // Create another MyQueue object
    std::list<int> values2 = {7, 8, 9, 10};
    MyQueue<int> queue2(values2);

    // Display the contents of queue2
    std::cout << "Queue2: " << queue2 << std::endl;

    // Merge queue2 into the original queue
    try {
        queue.Merge(queue2);
        std::cout << "Merged Queue: " << queue << std::endl;
    } catch (const std::overflow_error& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    // Find the common elements between the two queues
    MyQueue<int> commonElementsQueue = queue.FindCommonQueueElements(queue, queue2);
    std::cout << "Common Elements Queue: " << commonElementsQueue << std::endl;

    return 0;
}
