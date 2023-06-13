#include "Flight.h"
#include "functionalities.h"
#include<iostream>
#include<list>
#include "FlightType.h"

int main(){
    Flight *f1 = new Flight("1",60,500.0f,FLIGHT_TYPE::COMMERCIAL);
    Flight *f2 = new Flight("2",50,400.0f,FLIGHT_TYPE::COURIER);
    Flight *f3 = new Flight("3",120,1500.0f,FLIGHT_TYPE::COMMERCIAL);

    std::list<Flight*> flight = {f1,f2,f3};

    std::list<std::function<int(std::list<Flight*> &v)>> fun ={countSeat,combinedSeat};
    highestFlightDistance(flight);
    highestSeatCount(flight);
    operation(flight,fun);
}