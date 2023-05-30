#include "ConfirmedTravelTrip.h"

ConfirmedTravelTrip::ConfirmedTravelTrip(std::string start, std::string end, float distance, CAR_TYPE carType, TRAFFIC_STATE trafficState)
: TravelTrip(start,end,distance) , travelTripBookedCar{carType} , travelTripTrafficCondition{trafficState}{}

ConfirmedTravelTrip::~ConfirmedTravelTrip()
{
    std::cout<<"Confirmed\n";
}

std::string displayCar(enum class CAR_TYPE type){
    if(type == CAR_TYPE::BASIC){
        return "BASIC";
    } else if(type == CAR_TYPE::NEO){
        return "NEO";
    } else {
        return "PRIME";
    }
}

std::string displayTraffic(enum class TRAFFIC_STATE type){
    if(type == TRAFFIC_STATE::HEAVY){
        return "HEAVY";
    } else if(type == TRAFFIC_STATE::LIGHT){
        return "LIGHT";
    } else {
        return "MODERATE";
    }
}

float ConfirmedTravelTrip::totalTripFare()
{
    float fare= 0;
    if(getCarType() == CAR_TYPE::PRIME){
        fare = getTravelDistance() *1.8;
    } else if(getCarType() == CAR_TYPE::NEO){
        fare = getTravelDistance() * 1.5;
    }else {
        fare = getTravelDistance() * 1.2;
    }
    return fare;
}

float ConfirmedTravelTrip::totaTripTimeInMinutes()
{
    float time= 0;
    if(getTripType() == TRAFFIC_STATE::HEAVY){
        time = (1.8 * getTravelDistance()) + 30;
    } else if(getTripType() == TRAFFIC_STATE::HEAVY){
        time = (1.5 * getTravelDistance()) + 20;
    }else {
        time = (1.3 * getTravelDistance()) + 10;
    }
    return time;
}

std::ostream &operator<<(std::ostream &os, const ConfirmedTravelTrip &rhs) {
    os << "travelTripBookedCar: " <<displayCar(rhs.travelTripBookedCar)<<"\n"
       << " travelTripTrafficCondition: " <<displayTraffic(rhs.travelTripTrafficCondition)<<"\n";
    return os;
}


