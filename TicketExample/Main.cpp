#include "TicketCategory.h"
#include "TicketStatus.h"
#include "Ticket.h"

int main(){
    Ticket<enum class TicketStatus,int> *ticket = new Ticket<enum class TicketStatus,int>
    (TicketStatus::CONFIRMED,1800,"Gaya","NDLS");
    std::cout<<*ticket<<"\n";
    delete ticket; 
    return 0;
}