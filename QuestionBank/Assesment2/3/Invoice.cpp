#include "Invoice.h"

//constructor
Invoice::Invoice(std::string number, INVOICE_TYPE type, int items) : invoiceNumber{number}, invoicetype{type}, invoiceItems{items}
{
}
//destructor
Invoice::~Invoice()
{
    std::cout<<"Invoice destroyed\n";
}
//frined function to display data
std::ostream &operator<<(std::ostream &os, const Invoice &rhs) {
    os << "invoiceNumber: " << rhs.invoiceNumber
       << " invoicetype: " <<displayEnum(rhs.invoicetype)
       << " invoiceItems: " << rhs.invoiceItems;
    return os;
}
//display enum function to displaycategorical data
std::string displayEnum(enum class INVOICE_TYPE type)
{
    if (type == INVOICE_TYPE::SMS_GENERATED)
    {
        return "SMS_GENERATED";
    }
    else if (type == INVOICE_TYPE::PAPER_SLIP)
    {
        return "PAPER_SLIP";
    }
    else
    {
        return "E_BILL";
    }
}