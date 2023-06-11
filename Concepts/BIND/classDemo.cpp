#include <iostream>
#include <functional>

class Car {
    std::string name;
public:
    Car(std::string name) : name(name) {}

    void drive(int speed) {
        std::cout << name << " is driving at speed: " << speed << " km/h" << std::endl;
    }

    void stop() {
        std::cout << name << " has stopped" << std::endl;
    }
};

class Driver {
public:
    void performDrivingAction(std::function<void(int)> drivingAction, int speed) {
        drivingAction(speed);
    }

    void performStopAction(std::function<void()> stopAction) {
        stopAction();
    }
};

int main() {
    Car car("Tesla Model 3");
    Driver driver;

    // Using std::bind to bind member function drive() with a specific car object
    auto driveAction = std::bind(&Car::drive, &car, std::placeholders::_1);

    // Using std::bind to bind member function stop() with a specific car object
    auto stopAction = std::bind(&Car::stop, &car);

    // Perform driving action
    driver.performDrivingAction(driveAction, 100);

    // Perform stop action
    driver.performStopAction(stopAction);

    return 0;
}
