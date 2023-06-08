#include <iostream>
#include "Vehicle.h"
#include "Car.h"
#include "Bike.h"
#include <array>
#include <variant>

using TYPE = std::variant<Car *, Bike *>;

/*
     a function that creates two bikes,3 cars ND stores them in a common data conatiner.
     The functionshould then call calculateRtoTax oneach vehicle object stored
*/
void task()
{
    TYPE v1 = new Bike("bk1", 2245.4f, "007x");
    TYPE v2 = new Bike("bk2", 145.4f, "7x");
    TYPE v3 = new Car("ck1", 245.4f, "9x");
    TYPE v4 = new Car("ck2", 345.4f, "10x");
    TYPE v5 = new Car("ck3", 445.4f, "11x");

    // Bike *v1 = new Bike("bk1",45.4f,"007x");
    // Car *v3 = new Car("ck1",245.4f,"9x");
    std::array<TYPE, 5> data = {v1, v2, v3, v4, v5};

    for (auto &it : data)
    {
        std::visit([](auto arg)
                   { arg->calculateRtoTax(); },
                   it);
    }
    for (auto &it : data)
    {
        std::visit([](auto arg)
                   { delete arg; },
                   it);
    }
}

int main()
{
    task();
}