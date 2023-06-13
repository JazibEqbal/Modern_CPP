#ifndef FLIGHT_H
#define FLIGHT_H
#include <iostream>
#include "FlightType.h"

class Flight
{
private:
    std::string flightId;
    int flightSeatCount; // data members
    float flightDistance;
    enum class FLIGHT_TYPE flightType;

public:
    Flight() = default;
    Flight(const Flight &obj) = default;
    Flight(std::string id, int seat, float distance, enum class FLIGHT_TYPE type);
    Flight(std::string id, int seat, enum class FLIGHT_TYPE type);
    ~Flight();

    // setters and getters
    std::string getFlightId() const { return flightId; }
    void setFlightId(const std::string &flightId_) { flightId = flightId_; }

    int getFlightSeatCount() const { return flightSeatCount; }
    void setFlightSeatCount(int flightSeatCount_) { flightSeatCount = flightSeatCount_; }

    float getFlightDistance() const { return flightDistance; }
    void setFlightDistance(float flightDistance_) { flightDistance = flightDistance_; }

    enum class FLIGHT_TYPE getFlightType() const { return flightType; };

    friend std::ostream &operator<<(std::ostream &os, const Flight &rhs);
};

std::string displayEnum(enum class FLIGHT_TYPE type);

#endif // FLIGHT_H
