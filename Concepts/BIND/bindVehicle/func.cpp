#include "func.h"

float findAveragePrice(const std::list<Vehicle>& vehicles) {
    if (vehicles.empty())
        return 0.0f;

    // Lambda function to calculate the sum of vehicle prices
    auto sumFunction = [](const std::list<Vehicle>& v) {
        float sum = 0.0f;
        for (const Vehicle& vehicle : v) {
            sum += vehicle.getVehiclePrice();
        }
        return sum;
    };

    // Using std::bind to bind the lambda function to a std::function
    std::function<float(const std::list<Vehicle>&)> sumBinder = std::bind(sumFunction, std::placeholders::_1);

    // Invoking the bound function with the vehicles list
    float sum = sumBinder(vehicles);
    float averagePrice = sum / vehicles.size();
    return averagePrice;
}

void findGivenVehicleType(const std::list<Vehicle>& vehicles, VEHICLE_TYPE type) {
    // Lambda function to display vehicles of a given type
    auto displayFunction = [](const std::list<Vehicle>& v, VEHICLE_TYPE t) {
        for (const Vehicle& vehicle : v) {
            if (vehicle.getVehicleType() == t) {
                std::cout << "Vehicle Name: " << vehicle.getVehicleName() << std::endl;
                std::cout << "Vehicle Type: " << static_cast<int>(vehicle.getVehicleType()) << std::endl;
                std::cout << std::endl;
            }
        }
    };

    // Using std::bind to bind the lambda function to a std::function
    std::function<void(const std::list<Vehicle>&, VEHICLE_TYPE)> displayBinder = std::bind(displayFunction, std::placeholders::_1, type);

    // Invoking the bound function with the vehicles list and the given type
    displayBinder(vehicles, type);
}

void countOfGivenTypes(const std::list<Vehicle>& vehicles, const std::list<VEHICLE_TYPE>& types) {
    // Lambda function to count vehicles of given types
    auto countFunction = [](const std::list<Vehicle>& v, const std::list<VEHICLE_TYPE>& t) {
        int count = 0;
        for (const Vehicle& vehicle : v) {
            if (std::find(t.begin(), t.end(), vehicle.getVehicleType()) != t.end()) {
                count++;
            }
        }
        return count;
    };

    // Using std::bind to bind the lambda function to a std::function
    std::function<int(const std::list<Vehicle>&, const std::list<VEHICLE_TYPE>&)> countBinder = std::bind(countFunction, std::placeholders::_1, types);

    // Invoking the bound function with the vehicles list and the list of vehicle types
    int totalCount = countBinder(vehicles, types);

    std::cout << "Total Count: " << totalCount << std::endl;
}
