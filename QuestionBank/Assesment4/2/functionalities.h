#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H
#include "Manufacture.h"
#include<iostream>
#include<algorithm>
#include<functional>
#include<vector>
#include<unordered_map>
#include<memory>
#include<numeric>
#include<optional>
#include<list>
#include<set>

using Pointer = std::shared_ptr<Manufacture>; //shared pointer to object
using Conatiner = std::vector<Pointer>;       //creating vector of pointer objects

//function to create objects for data set
extern std::function<void(Conatiner&) > createEnteries;

extern std::function<int(Conatiner&, int) > countCarUnits;

extern std::function<float(Conatiner&) > averageOfHorsePower;

extern std::function<int(Conatiner&) > combinedInsuranceCost;

extern std::function<std::string(Conatiner&) > modelOfMaximumHorsePower;

extern std::function<std::optional<std::set<MANUFACTURER_TYPE>>(Conatiner&) > uniqueCarBrands;

extern std::function<std::optional<std::list<std::string>>(Conatiner&, int) > modelsAboveThreshold; 

#endif // FUNCTIONALITIES_H
