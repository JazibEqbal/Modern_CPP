#ifndef TICKET_H
#define TICKET_H
#include<iostream>
#include "TicketCategory.h"
#include "TicketStatus.h"

template<typename T,typename U>
class Ticket
{
private:
    T ticketType;
    U ticketPrice;
    std::string ticketStartLocation;
    std::string ticketEndLocation;
public:
    Ticket() = delete;
    Ticket(const Ticket<T,U> &obj) = default;
    Ticket(T type, U price, std::string startLocation, std::string endLocation);
    Ticket(T type,std::string startLocation, std::string endLocation);
    ~Ticket();

    std::string getTicketStartLocation() const { return ticketStartLocation; }
    void setTicketStartLocation(const std::string &ticketStartLocation_) { ticketStartLocation = ticketStartLocation_; }

    std::string getTicketEndLocation() const { return ticketEndLocation; }
    void setTicketEndLocation(const std::string &ticketEndLocation_) { ticketEndLocation = ticketEndLocation_; }

    U getTicketPrice() const { return ticketPrice; }
    void setTicketPrice(const U &ticketPrice_) { ticketPrice = ticketPrice_; }

    template<typename A,typename B>
    friend std::ostream &operator<<(std::ostream &os, const Ticket<A, B> &rhs){
    os << "Ticket Type is: " << setTicketType(rhs.ticketType) <<"\n"
       << "Ticket Price is: " << rhs.ticketPrice <<"\n"
       << "Ticket Start Location is: " << rhs.ticketStartLocation <<"\n"
       << "Ticket End Location is: " << rhs.ticketEndLocation;
    return os;
    }    
};

template <typename T, typename U>
inline Ticket<T, U>::Ticket(T type, U price, std::string startLocation, std::string endLocation) 
 : ticketType{type}, ticketPrice{price}, ticketStartLocation{startLocation}, ticketEndLocation{endLocation} {}

template <typename T, typename U>
inline Ticket<T, U>::Ticket(T type, std::string startLocation, std::string endLocation)
 : ticketType{type}, ticketStartLocation{startLocation}, ticketEndLocation{endLocation} {}

std::string setTicketType(enum class TicketCategory type){
        if(type == TicketCategory::GENERAL){
            return "GENERAL";
        } else if(type == TicketCategory::AC){
            return "AC";
        } else {
            return "SLEEPER";
        }
    };
std::string setTicketType(enum class TicketStatus type){
        if(type == TicketStatus::CONFIRMED){
            return "CONFIRMED";
        } else if(type == TicketStatus::WAITING){
            return "WAITING";
        } else {
            return "VIP_RESERVED";
        }
    }
template <typename T, typename U>
inline Ticket<T, U>::~Ticket()
{
    std::cout<<"Ticket destroyed\n";
};

#endif // TICKET_H
