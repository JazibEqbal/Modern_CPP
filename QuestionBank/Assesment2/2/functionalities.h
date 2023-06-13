#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include "Flight.h"
#include <list>
#include <iostream>
#include <functional>
#include<numeric>

void operation(std::list<Flight *> &acc, std::list<std::function<int(std::list<Flight *> &v)>> fun);

extern std::function<int(std::list<Flight *> &obj)> countSeat;

extern std::function<std::string(std::list<Flight *> &obj)> highestFlightDistance;

extern std::function<float(std::list<Flight *> &obj)> highestSeatCount;

extern std::function<int(std::list<Flight *> &obj)> combinedSeat;

#endif // FUNCTIONALITIES_H
