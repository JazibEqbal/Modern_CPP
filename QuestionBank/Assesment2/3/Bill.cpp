#include "Bill.h"

//constructor
Bill::Bill(float amount, float tax, std::reference_wrapper<Invoice *> invoice) 
: billAmount{amount}, billtaxAmount{tax}, billAssociatedInvoice{invoice} {}

//destructor
Bill::~Bill()
{
    std::cout<<"Bill destroyed\n";
}
//friend function to display data
std::ostream &operator<<(std::ostream &os, const Bill &rhs) {
    os << "billAmount: " << rhs.billAmount
       << " billtaxAmount: " << rhs.billtaxAmount
       << " billAssociatedInvoice: " << rhs.billAssociatedInvoice;
    return os;
}
