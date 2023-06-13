#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H
#include "Invoice.h"
#include "Bill.h"
#include<functional>
#include<list>
#include<iostream>

//function to return highest bill amount
extern std::function<std::string(std::list<Bill*> &obj) > highestBillAmount;

//function to find if passed invoice number matches the data stored in Bill objects or not
extern std::function<float(std::list<Bill*> &obj,std::string number) > billAmount;

//a function to return billAssociateddInvoice instances in a container whose billAmount is above threshold
extern std::function<std::list<Invoice*>(std::list<Bill*> &obj,float threshold) > billassociate; 

#endif // FUNCTIONALITIES_H
