#include "TicketCategory.h"
#include "TicketStatus.h"
#include "Ticket.h"

int main(){
    Ticket<enum class TicketStatus,int> *ticket = new Ticket<enum class TicketStatus,int>
    (TicketStatus::WAITING,100,"Gaya Junction","NDLS");
    std::cout<<*ticket<<"\n";
    std::cout<<ticket->getTicketPrice()<<"\n";
    delete ticket; 
    return 0;
}