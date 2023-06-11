#include <iostream>
#include <functional>
#include <vector>

class NumberProcessor {
public:
    using NumberOperation = std::function<void(int&)>;

    void addNumberOperation(NumberOperation operation) {
        numberOperations_.push_back(operation);
    }

    void processNumbers(std::vector<int>& numbers) {
        for (auto& number : numbers) {
            for (const auto& operation : numberOperations_) {
                operation(number);
            }
        }
    }

private:
    std::vector<NumberOperation> numberOperations_;
};

int main() {
    NumberProcessor numberProcessor;

    auto doubleNumber = [](int& number) {
        number *= 2;
    };

    auto squareNumber = [](int& number) {
        number *= number;
    };

    std::reference_wrapper<decltype(doubleNumber)> doubleRef(doubleNumber);
    std::reference_wrapper<decltype(squareNumber)> squareRef(squareNumber);

    numberProcessor.addNumberOperation(doubleRef);
    numberProcessor.addNumberOperation(squareRef);

    std::vector<int> numbers = {1, 2, 3, 4, 5};

    numberProcessor.processNumbers(numbers);

    for (const auto& number : numbers) {
        std::cout << number << " ";
    }
    std::cout << std::endl;

    return 0;
}
