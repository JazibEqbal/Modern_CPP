#include "TrafficState.h"
#include "TravelTrip.h"
#include "CarType.h"
#include "ConfirmedTravelTrip.h"
#include<list>
#include "functionalities.h"

int main(){
    TravelTrip *t1 = new ConfirmedTravelTrip("a","b",20.4f,CAR_TYPE::BASIC,TRAFFIC_STATE::HEAVY);
    TravelTrip *t2 = new ConfirmedTravelTrip("asss","bsss",199.4f,CAR_TYPE::NEO,TRAFFIC_STATE::MODERATE);

    std::list<ConfirmedTravelTrip*> list = {t1,t2};

    std::cout<<"Average Price is: "<<FindAverageTravelTime(list)<<"\n";
    return 0;
}