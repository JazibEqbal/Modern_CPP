#include "functionalities.h"

float FindAverageTravelTime(std::list<ConfirmedTravelTrip *> &obj)
{
    float totalTime= 0;
    int count=0;
    for(auto* it: obj){                                // looping through each object 
        if(obj.size() <= 0){
            throw std::runtime_error("Car list is empty");    // thrwoing an error if list size is equal or smaller than 0
        }
        totalTime += it->totaTripTimeInMinutes();     //adding every object time to total 
    };
    return (totalTime/count);
}

float FindMinimumTripFare(std::list<ConfirmedTravelTrip *> &obj)
{
    int min = INT16_MAX;                        // initializing minimum with a larger value
    for(auto *it : obj){
        if(obj.size() <= 0){
            throw std::runtime_error("Car list is empty");   // thrwoing an error if list size is equal or smaller than 0
        }
        if(min > it->totalTripFare()){              //checking if minimum is greater than current obj trip fare
            min = it->totalTripFare();              //updating minimum
        }
    }
    return min;
}

int FindCountOfGivenBookingType(std::list<ConfirmedTravelTrip*> &obj, enum class CAR_TYPE type){
    int count =0;
    for(auto* it: obj){
        if(obj.size() <= 0){
            throw std::runtime_error("Car list is empty"); // thrwoing an error if list size is equal or smaller than 0
        }
        if(type == it->getCarType()){
            count++;      //incrementing count if cartype is equal to car type in current obj
        }
    }
    return count;
}

