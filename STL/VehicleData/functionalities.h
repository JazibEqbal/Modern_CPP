#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H
#include<optional>
#include<functional>
#include<algorithm>
#include<list>
#include<iostream>
#include "VehcileData.h"

void operation(std::list<VehcileData *> &v,std::list<std::function<float(std::list<VehcileData*> &veh)>> fun);

extern std::function<float(std::list<VehcileData*> obj) > AverageFuelCapacity;

extern std::function<float(std::list<VehcileData*> obj) > FindMileage;

#endif // FUNCTIONALITIES_H