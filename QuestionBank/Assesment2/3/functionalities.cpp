#include "functionalities.h"

// function to return highest bill amount
std::function<std::string(std::list<Bill *> &obj)> highestBillAmount = [](std::list<Bill *> &obj)
{
    float max = 0.0f;
    auto invoice = obj.front()->getBillAssociatedInvoice().get()->getInvoiceNumber(); // getting first invoice number
    if (obj.empty())
    {
        throw std::runtime_error("List passed is empty"); // thrwoing error if list passed is empty
    }
    for (auto *it : obj) // looping over every objects and checking the conditions
    {
        if (it->getBillAmount() > max) // checking if bill amount is greater than current objects billAmount or not
        {
            max = it->getBillAmount();                                          // if greater, assigning max to current objects bill amount
            invoice = it->getBillAssociatedInvoice().get()->getInvoiceNumber(); // updating invoice number to current objects invoice number
        }
    }
    return invoice; // returning invoice number whose nill amount is highest
};

// function to find if passed invoice number matches the data stored in Bill objects or not
std::function<float(std::list<Bill *> &obj, std::string number)> billAmount = [](std::list<Bill *> &obj, std::string invoiceNumber)
{
    float amount = 0.0f;
    if (obj.empty())
    {
        throw std::runtime_error("List passed is empty"); // thrwoing error if list passed is empty
    }
    for (auto *it : obj) // looping over every objects and checking the conditions
    {
        // if bill associated invoice number is equal to passed invoice number then returning it
        if (it->getBillAssociatedInvoice().get()->getInvoiceNumber() == invoiceNumber)
        {
            return amount = it->getBillAmount(); // returning if found
        }
    }
};

// a function to return billAssociateddInvoice instances in a container whose billAmount is above threshold
std::function<std::list<Invoice *>(std::list<Bill *> &obj, float threshold)> billassociate = [](std::list<Bill *> &obj, float threshold)
{
    std::list<Invoice *> list(obj.size());
    if (obj.empty())
    {
        throw std::runtime_error("List passed is empty"); // thrwoing error if list passed is empty
    }
    if (threshold < 0)
    {
        throw std::runtime_error("Threshold can't be a negative value"); // throwing error if threshold provided is negative
    }
    for (auto *it : obj) // looping over every objects and checking the conditions
    {
        if (it->getBillAmount() > threshold) // if current object's bill amount is greater than threshold then pushing it into the list
        {
            list.emplace_back(it->getBillAssociatedInvoice()); // pushing into list if above condition satisfies
        }
    }
    return list; // returning the list here
};