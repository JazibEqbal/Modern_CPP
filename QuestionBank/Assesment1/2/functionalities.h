#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H
#include "TrafficState.h"
#include "TravelTrip.h"
#include "CarType.h"
#include "ConfirmedTravelTrip.h"
#include<list>

float FindAverageTravelTime(std::list<ConfirmedTravelTrip*> &obj);

float FindMinimumTripFare(std::list<ConfirmedTravelTrip*> &obj);

int FindCountOfGivenBookingType(std::list<ConfirmedTravelTrip*> &obj, enum class CAR_TYPE type);

#endif // FUNCTIONALITIES_H
