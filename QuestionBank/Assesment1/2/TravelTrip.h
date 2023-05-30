#ifndef TRAVELTRIP_H
#define TRAVELTRIP_H
#include<iostream>

class TravelTrip
{
private:
    std::string travelStartLocation;
    std::string travelEndLocation;
    float travelDistance;
public:
    TravelTrip() = delete;                  //deleted default constructor
    TravelTrip(const TravelTrip &obj) = delete;             //deleted copy constructor
    TravelTrip(std::string start,std::string end,float distance);  //parameterizzed constructor
    virtual float totalTripFare() = 0;    //pure virtual function to calc totalTripFare
    virtual float totaTripTimeInMinutes() = 0;  //pure virtual function to calc totalTripTime
    virtual ~TravelTrip();   // a virtual destructor

    //all getters and setters

    std::string getTravelStartLocation() const { return travelStartLocation; }
    void setTravelStartLocation(const std::string &travelStartLocation_) { travelStartLocation = travelStartLocation_; }

    std::string getTravelEndLocation() const { return travelEndLocation; }
    void setTravelEndLocation(const std::string &travelEndLocation_) { travelEndLocation = travelEndLocation_; }

    float getTravelDistance() const { return travelDistance; }
    void setTravelDistance(float travelDistance_) { travelDistance = travelDistance_; }
};

#endif // TRAVELTRIP_H
