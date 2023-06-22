#include "Car.h"



Car::Car(std::variant<int, std::string> Id, int Registration, VehicleType vType, insuranceptr InsurancePlan, CarType Type, float Price, std::string Colour):
Vehicle(Id,Registration,vType,InsurancePlan),carType(Type),carPrice(Price),carColour(Colour)
{
}
