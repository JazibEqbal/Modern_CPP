#include "Car.h"
#include "CarCategory.h"
#include "functionalities.h"

int FindAverageFuelCapacity(std::list<Car *> &obj)
{
    if (obj.size() <= 0)
    {
        throw std::runtime_error("Car list is empty");
    }
    int count = 0; // initilizing count to count number of cars
    int total = 0;
    for (auto *it : obj)
    {
        total += it->getCarFuelCapacity(); // adding every car fuel to total
        count++;                           // incrementing car count by 1 every time
    }
    return (total / count); // returning averagePrice by dividing total by count
}

int FindCountOfGivenBrands(std::list<Car *> &obj, CAR_CATEGORY type)
{
    int count = 0;
    for (auto *it : obj)
    { // for each object of car checks if passed value is equal to category or not
        if (obj.size() <= 0)
        {
            throw std::runtime_error("Car list is empty");
        }
        if (it->getCategory() == type)
        {
            count++; // if equals increment count by 1
        }
    }
    return count; // returning total count
}

void FindBestPassengerCar(std::list<Car *> &obj, CAR_CATEGORY cat)
{
    // initializing max value to 0
    int max = 0;
    for (auto *it : obj)    //looping through list of objects tofind maximumseat count
    {
        if (obj.size() <= 0)
        {
            throw std::runtime_error("Car list is empty");
        }
        if (cat == it->getCategory())
        {
            if (max < it->getCarSeatCount())
            {
                max = it->getCarSeatCount(); // finding maximum seat count and if max is greater than seat count then updating max to seat
            }
        }
        if (cat==it->getCategory() && max == it->getCarSeatCount())
        {
            std::cout << "Car Brand: " << it->getCarBrand() << "\n";
            std::cout << "Car Model: " << it->getCarModel() << "\n";
        }
    }
}
