#ifndef CONFIRMEDTRAVELTRIP_H
#define CONFIRMEDTRAVELTRIP_H
#include "TravelTrip.h"
#include "CarType.h"
#include "TrafficState.h"
#include <ostream>

class ConfirmedTravelTrip : public TravelTrip
{
private:
    enum class CAR_TYPE travelTripBookedCar;            
    enum class TRAFFIC_STATE travelTripTrafficCondition;
public:
    ConfirmedTravelTrip(std::string start,std::string end,float distance,enum class CAR_TYPE carType,enum class TRAFFIC_STATE trafficState);
    ~ConfirmedTravelTrip();

    float totalTripFare() override;           // overriding from base class
    float totaTripTimeInMinutes() override;   //overriding from base class

    enum class CAR_TYPE getCarType() const { return travelTripBookedCar;};   //getting CAR_TYPE
    enum class TRAFFIC_STATE getTripType() const { return travelTripTrafficCondition;};  //getting TRAFFIC_STATE

    friend std::ostream &operator<<(std::ostream &os, const ConfirmedTravelTrip &rhs);  

};

std::string displayCar(enum class CAR_TYPE type); // function to display enum of CAR_TYPE
std::string displayTraffic(enum class TRAFFIC_STATE type); // function to display enum of TRAFFIC_STATE

#endif // CONFIRMEDTRAVELTRIP_H
