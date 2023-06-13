#include <iostream>
#include "CarUnit.h"
#include "CarInstrucment.h"
#include "CarUnitType.h"
#include <iostream>
#include <functional>
#include <list>
#include "functionalities.h"

std::string cCarUnit(enum class CAR_UNIT_TYPE type)
{
    if (type == CAR_UNIT_TYPE::BASE)
    {
        return "BASE";
    }
    else if (type == CAR_UNIT_TYPE::TOP_MODEL)
    {
        return "TOP_MODEL";
    }
    else
    {
        return "EXTENDED";
    }
}

int main()
{
    //creating car objects
    CarUnit *unit1 = new CarUnit("1", 1, CAR_UNIT_TYPE::BASE, 20, CAR_INSTRUCMENT::ANALOG, "blue", 12, 4);
    CarUnit *unit2 = new CarUnit("2", 2, CAR_UNIT_TYPE::EXTENDED, 10, CAR_INSTRUCMENT::HYBRID, "red", 18, 6);
    CarUnit *unit3 = new CarUnit("3", 3, CAR_UNIT_TYPE::EXTENDED, 30, CAR_INSTRUCMENT::ANALOG, "blue", 22, 4);

    //list of car unit objects
    std::list<CarUnit *> list = {unit1, unit2, unit3};

    // binding function OperationB
    auto bindedOPerationB = std::bind(
        &operationB,
        [](std::list<CarUnit *> obj, int capacity = 10)
        {
            for (auto *it : obj)        //looping over objects
            {
                if(obj.empty()){
                    throw std::runtime_error("List passed is empty"); //throwing error if list passed is empty
                }
                if (it->getCarUnitFuelTankCapacity() > 10) //if capacity is greater than 10
                {
                    std::cout << it;
                }
            }
        },
        std::placeholders::_2);
    
    //binding highestSeat function 
    auto BindHighestSeat = std::bind(HighestSeatCountInCategory, list, std::placeholders::_2);

    //calling the functions
    std::cout<<cCarUnit(HighestCarType(list))<<"\n";
    std::cout<<HighestSeatCountInCategory(list,CAR_UNIT_TYPE::BASE)<<"\n";

    //clearing the memory
    for (auto *it : list)
    {
        delete it;
    }
    // calling functions
}

