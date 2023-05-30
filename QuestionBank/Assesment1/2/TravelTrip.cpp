#include "TravelTrip.h"

TravelTrip::TravelTrip(std::string start, std::string end, float distance) : travelStartLocation{start},
travelEndLocation{end}, travelDistance{distance} {}

TravelTrip::~TravelTrip()
{
    std::cout<<"Travel des\n";
}
