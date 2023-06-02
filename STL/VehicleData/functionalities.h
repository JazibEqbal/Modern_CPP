#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H
#include<optional>
#include<functional>
#include<algorithm>
#include<list>
#include<iostream>
#include "VehcileData.h"

std::optional<int> AverageFuelCapacity(std::list<VehcileData*> &data);

std::optional<const VehcileData*> FindMileage(std::list<VehcileData*> &data, std::string id);

#endif // FUNCTIONALITIES_H
