#include "Invoice.h"
#include "Bill.h"
#include <functional>
#include <iostream>
#include <list>
#include "functionalities.h"

int main()
{
    // creating invoice objects
    Invoice *i = new Invoice("1", INVOICE_TYPE::E_BILL, 10);
    Invoice *i2 = new Invoice("2", INVOICE_TYPE::SMS_GENERATED, 12);
    Invoice *i3 = new Invoice("3", INVOICE_TYPE::E_BILL, 4);

    // creating bill objects
    Bill *b1 = new Bill(200.20f, 40.00f, std::ref(i));
    Bill *b2 = new Bill(100.20f, 140.00f, std::ref(i2));
    Bill *b3 = new Bill(400.20f, 240.00f, std::ref(i3));

    std::list<Bill *> bills = {b1, b2, b3}; // crearing list of bill objects
    highestBillAmount(bills);

    billAmount(bills, "1");
    // bind function to bind billAssociate function and fixing threshold to 100
    auto boundbillassociate = std::bind(billassociate, std::placeholders::_1, 100);
    // calling bind function
    boundbillassociate(bills);

    // clearing the memory
    for (auto *it : bills)
    {
        delete it;
    }
    delete i;
    delete i3;
    delete i2;
}