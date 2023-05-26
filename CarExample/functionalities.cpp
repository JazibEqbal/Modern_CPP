#include "functionalities.h"
#include "Car.h"

float FindHighestInsurance(std::list<Car *> &car)
{
    float max = INT32_MIN;
    for(auto* it: car){
        if(car.size() <= 0){
            throw std::runtime_error("Car list is empty");
        }
        if(it->calculateInsuranceAmount() > max){
            max = it->calculateInsuranceAmount();
        }
    }
    return max;
}

int FindCountOfGivenType(std::list<Car *> &car, CarType type, float limit)
{
    int count=0;
    for(auto* it: car){
        if(car.size() <=0) {
            throw std::runtime_error("Car list is empty");
        }
        if(it->getCarType() == type && it->getCarPrice() <= limit){
            count++;
        }
    }
    return count;
}

/*
    catch(const string* msg){
        std::cout<<msg;
    }

*/