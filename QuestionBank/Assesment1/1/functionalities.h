#include "Car.h"
#include "CarCategory.h"
#include<list>
#include<iostream>

int FindAverageFuelCapacity(std::list<Car*> &obj);

int FindCountOfGivenBrands(std::list<Car*> &obj, enum class CAR_CATEGORY category);

void FindBestPassengerCar(std::list<Car*> &obj, enum class CAR_CATEGORY);