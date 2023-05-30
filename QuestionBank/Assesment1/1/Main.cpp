#include "Car.h"
#include "CarCategory.h"
#include "functionalities.h"

int main()
{
    Car *c1 = new Car("1", "BMW", "007x", 43.5, CAR_CATEGORY::SUV, 96, 20);
    Car *c2 = new Car("2", "AUDI", "0x", 23.5, CAR_CATEGORY::SUV, 67, 120);

    // creating standard list of car objects
    std::list<Car *> list = {c1, c2};

    // std::cout<<"Count of given brand: "<<FindCountOfGivenBrands(list,CAR_CATEGORY::SEDAN)<<"\n";

    // std::cout<<"Average fuel capacity of cars is: "<<FindAverageFuelCapacity(list)<<"\n";

    // Finding best car for a passenger
    FindBestPassengerCar(list, CAR_CATEGORY::SUV);

    for (auto it : list)
    { // freeing the memory of eachcar objects
        delete it;
    }
}