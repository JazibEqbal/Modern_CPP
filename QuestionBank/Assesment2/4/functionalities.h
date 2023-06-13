#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H
#include "CarUnit.h"
#include <iostream>
#include <functional>
#include <list>
#include <iostream>
#include <algorithm>
#include "CarUnitType.h"

// operationA that takes list of carUnit objects and return the same
void operationA(std::function<std::list<CarUnit *>(std::list<CarUnit *> car)>, std::list<CarUnit *> carList);

// operationB that takes list of car unit objects and returns int
void operationB(std::function<int(std::list<CarUnit *>, int)>, std::list<CarUnit *>);

// functionto calculate highestSeatcount
extern std::function<CarUnit(std::list<CarUnit*>,CAR_UNIT_TYPE)> HighestSeatCountInCategory;

// function to calculate which has maximum car unit price
extern std::function<CAR_UNIT_TYPE(std::list<CarUnit *> &obj)> HighestCarType;

#endif // FUNCTIONALITIES_H
