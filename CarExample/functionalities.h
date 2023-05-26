#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H
#include "Car.h"
#include "CarType.h"
#include<iostream>
#include<list>

float FindHighestInsurance(std::list<Car*> &car);
int FindCountOfGivenType(std::list<Car*> &car,enum class CarType type, float limit);

#endif // FUNCTIONALITIES_H
