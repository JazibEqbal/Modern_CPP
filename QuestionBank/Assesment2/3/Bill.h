#ifndef BILL_H
#define BILL_H
#include<iostream>
#include<functional>
#include "Invoice.h"

class Bill
{
private:
//data members
    float billAmount;                      
    float billtaxAmount;
    std::reference_wrapper<Invoice *> billAssociatedInvoice;    //refernece wrapper which holds the instances of Invoice
public:
    Bill() = delete;        //deleted default constructor
    Bill(const Bill &obj) = default;    //defaulted copy constructor
    Bill(float amount,float tax,std::reference_wrapper<Invoice *> invoice); //constructor
    ~Bill();    //destructor

    //getters and setters
    float getBillAmount() const { return billAmount; }
    void setBillAmount(float billAmount_) { billAmount = billAmount_; }

    float getBilltaxAmount() const { return billtaxAmount; }
    void setBilltaxAmount(float billtaxAmount_) { billtaxAmount = billtaxAmount_; }

    std::reference_wrapper<Invoice *> getBillAssociatedInvoice() const { return billAssociatedInvoice; }
    void setBillAssociatedInvoice(const std::reference_wrapper<Invoice *> &billAssociatedInvoice_) { billAssociatedInvoice = billAssociatedInvoice_; }

    friend std::ostream &operator<<(std::ostream &os, const Bill &rhs);
};

#endif // BILL_H
