#include "functionalities.h"

// operationA
void operationA(std::function<std::list<CarUnit *>(std::list<CarUnit *>)> car, std::list<CarUnit *> carList)
{
    car(carList);
}

// operationB
void operationB(std::function<int(std::list<CarUnit *>, int)> function, std::list<CarUnit *> carList)
{
    function(carList, 20);
}

// function to find highestseat in category whose type matches to passed argument
std::function<CarUnit(std::list<CarUnit *>, CAR_UNIT_TYPE)> HighestSeatCountInCategory = [](std::list<CarUnit *> obj, CAR_UNIT_TYPE type)
{
    CarUnit *car;
    if (obj.empty())
    {
        throw std::runtime_error("Empty CarUnit !"); // thrwoing error if list passed is empty
    }
    int max = 0;
    for (auto &it : obj)
    { // looping over list of objects
        if (it->getCarUnitType() == type)
        { // if type matches passed type
            if (it->getCarUnitSeatCount() > max)
            {                                    // checking if seat count of object is greater than max or not
                max = it->getCarUnitSeatCount(); // assigning it to max if found greater
                car = it;                        // updating car object to current object type
            }
        }
    }
    return *car; // returning the car object
};

// function to find cartype which has highest car unit price
std::function<CAR_UNIT_TYPE(std::list<CarUnit *> &obj)> HighestCarType = [](std::list<CarUnit *> obj)
{
    if (obj.empty())
    {
        throw std::runtime_error("Empty CarUnit !"); // thrwoing error if list passed is empty
    }
    CAR_UNIT_TYPE type; // enum of car type
    float max = 0.0f;
    for (auto *it : obj)
    { // looping over list of objects
        if (it->getCarUnitCostPrice() > max)
        {                                    // checking if car price is greater than max
            max = it->getCarUnitCostPrice(); // if yes assigning it to carunit price
            type = it->getCarUnitType();     // updating the type to current object
        }
    }
    return type; // returning the type
};
