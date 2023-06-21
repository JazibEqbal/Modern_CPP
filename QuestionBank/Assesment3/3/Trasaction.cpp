#include "Trasaction.h"

Trasaction::Trasaction(myVariant id, float amount, TRANSACTION_TYPE type) : transactionId{id}, transactionAmount{amount},
                                                                            transactionType{type} {}

Trasaction::~Trasaction()
{
    std::cout << "Transaction Destroyed\n";
}
std::ostream &operator<<(std::ostream &os, const Trasaction &rhs)
{
    os << " Transaction Id: ";
    std::visit([&](auto arg)
               { os << arg; },
               rhs.transactionId);
    os << " transactionAmount: " << rhs.transactionAmount
       << " transactionType: " << displayEnum(rhs.transactionType);
    return os;
}
std::string displayEnum(enum class TRANSACTION_TYPE type)
{
    if (type == TRANSACTION_TYPE::CARD)
    {
        return "CARD";
    }
    else if (type == TRANSACTION_TYPE::CASH)
    {
        return "CASH";
    }
    else
    {
        return "UPI";
    }
}