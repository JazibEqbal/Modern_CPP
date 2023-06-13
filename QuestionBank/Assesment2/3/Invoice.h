#ifndef INVOICE_H
#define INVOICE_H
#include<iostream>
#include "InvoiceType.h"

class Invoice
{
private:
//data members
    std::string invoiceNumber;
    enum class INVOICE_TYPE invoicetype;  //enum for categorical data
    int invoiceItems;
public:
    Invoice() = default; //deleted default constructor
    Invoice(const Invoice &obj) = default; //defaulted copy constructor
    Invoice(std::string number,enum class INVOICE_TYPE type, int items); //constructor
    ~Invoice();     //destructor
    //overloaded << operator
    friend std::ostream &operator<<(std::ostream &os, const Invoice &rhs);

    //getters and setters
    enum class INVOICE_TYPE getInvoice() const {return invoicetype;};

    std::string getInvoiceNumber() const { return invoiceNumber; }
    void setInvoiceNumber(const std::string &invoiceNumber_) { invoiceNumber = invoiceNumber_; }

    int getInvoiceItems() const { return invoiceItems; }
    void setInvoiceItems(int invoiceItems_) { invoiceItems = invoiceItems_; }
};
//display enum function declaration
std::string displayEnum(enum class INVOICE_TYPE type);

#endif // INVOICE_H
