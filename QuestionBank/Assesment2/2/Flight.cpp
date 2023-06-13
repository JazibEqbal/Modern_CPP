#include "Flight.h"
// constructor
Flight::Flight(std::string id, int seat, float distance, FLIGHT_TYPE type) : flightId{id}, flightSeatCount{seat},
                                                                             flightDistance{distance}, flightType{type}
{
}
Flight::Flight(std::string id, int seat, FLIGHT_TYPE type) : flightId{id}, flightSeatCount{seat}, flightType{type}
{
}
// destructor
Flight::~Flight()
{
    std::cout << "Flight destroyed\n";
}
// friend function
std::ostream &operator<<(std::ostream &os, const Flight &rhs)
{
    os << "flightId: " << rhs.flightId
       << " flightSeatCount: " << rhs.flightSeatCount
       << " flightDistance: " << rhs.flightDistance
       << " flightType: " << displayEnum(rhs.flightType);
    return os;
}
// display enum
std::string displayEnum(enum class FLIGHT_TYPE type)
{
    if (type == FLIGHT_TYPE::COMMERCIAL)
    {
        return "COMMERCIAL";
    }
    else if (type == FLIGHT_TYPE::SPECIAL_OPS)
    {
        return "SPECIAL_OPS";
    }
    else
    {
        return "COURIER";
    }
}