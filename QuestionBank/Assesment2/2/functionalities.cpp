#include "functionalities.h"

void operation(std::list<Flight *> &flight, std::list<std::function<int(std::list<Flight *> &f)>> fun)
{
    for (auto &it : fun)
    {
        std::cout << it(flight) << "\n";
    }
}
// function to calculate countSeats
std::function<int(std::list<Flight *> &obj)> countSeat = [](std::list<Flight *> &obj)
{
    if (obj.empty())
    {
        throw std::runtime_error("List passed is empty"); // throwing error if passed list is empty
    }
    int count = 0;
    for (auto *it : obj) // looping through each object
    {
        if (it->getFlightSeatCount() > 50) // checking if seats is above 50 or not
        {
            count++; // if above incrementing count by 1
        }
    }
    return count;
};

std::function<std::string(std::list<Flight *> &obj)> highestFlightDistance = [](std::list<Flight *> obj)
{
    if (obj.empty())
    {
        throw std::runtime_error("List passed is empty"); // throwing error if passed list is empty
    }
    float max = 0.0f;
    auto id = obj.front()->getFlightId(); // setting first id
    for (auto *it : obj)                  // looping through each object
    {
        if (it->getFlightDistance() > max) // checking if flight distance is greater than max or not
        {
            max = it->getFlightDistance(); // if greater then assigning max to the distance of flight
            id = it->getFlightId();        // and changing the flightid to current object is
        }
    }
    return id; // returning the id which has maximum flight distance
};

// function to calculate highestSeatCount
std::function<float(std::list<Flight *> &obj)> highestSeatCount = [](std::list<Flight *> &obj)
{
    if (obj.empty())
    {
        throw std::runtime_error("List passed is empty"); // throwing error if passed list is empty
    }
    int seat = obj.front()->getFlightDistance(); // setting first object as my highest flight distance
    int max = 0;
    for (auto *it : obj)
    {
        if (it->getFlightSeatCount() > max) // checking if seat count is greater than max or not
        {
            max = it->getFlightSeatCount(); // it greater then modifing the max to current flight seat count
            seat = it->getFlightDistance(); // modifying seat to the current object flight distance
        }
    }
    return seat; // returning the objects seat which has maximum flight distance
};

std::function<int(std::list<Flight *> &obj)> combinedSeat = [](std::list<Flight *> &obj)
{
    if (obj.empty())
    {
        throw std::runtime_error("List passed is empty"); // throwing error if passed list is empty
    }
    int total = 0;
    for (auto *it : obj)
    {
        total += it->getFlightSeatCount(); // adding seats for each object to total
    }
    return total;
};

// ALGORITHM WAY STL

std::function<int(std::list<Flight *> &obj)> countSeat = [](std::list<Flight *> &obj)
{
    if (obj.empty())
    {
        throw std::runtime_error("List passed is empty");
    }
    int count = std::count_if(obj.begin(), obj.end(), [](Flight *f)
                              { return f->getFlightSeatCount() > 50; });
    return count;
};

std::function<std::string(std::list<Flight *> &obj)> highestFlightDistance = [](std::list<Flight *> obj)
{
    if (obj.empty())
    {
        throw std::runtime_error("List passed is empty");
    }
    float max = 0.0f;
    auto id = obj.front()->getFlightId();
    std::for_each(obj.begin(), obj.end(), [&](Flight *f){
        if (f->getFlightDistance() > max){
            max = f->getFlightDistance();     
            id = f->getFlightId();            
        }
    });
    return id;
};

std::function<float(std::list<Flight *> &obj)> highestSeatCount = [](std::list<Flight *> &obj)
{
    if (obj.empty())
    {
        throw std::runtime_error("List passed is empty"); // throwing error if passed list is empty
    }
    int seat = obj.front()->getFlightDistance(); // setting first object as my highest flight distance
    int max = 0;

    std::for_each(obj.begin(),obj.end(),[&](Flight *f){
        if (f->getFlightSeatCount() > max) 
        {
            max = f->getFlightSeatCount();
            seat = f->getFlightDistance(); 
        }
    });
    return seat; 
};

std::function<int(std::list<Flight *> &obj)> combinedSeat = [](std::list<Flight *> &obj)
{
    if (obj.empty())
    {
        throw std::runtime_error("List passed is empty"); // throwing error if passed list is empty
    }
    int total = std::accumulate(obj.begin(),obj.end(),0);
    return total;
};