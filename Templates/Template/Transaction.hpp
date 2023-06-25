#include "Transaction.h"

template <typename T, typename U>
Transaction<T, U>::Transaction(T id, float amount, bool status, U name, TRANSACTION_TYPE type)
    : transactionId{id}, transactionAmount{amount}, transactionStatus{status}, transactionName{name}, transactionType{type} {}

template <typename T, typename U>
Transaction<T, U>::~Transaction()
{
    std::cout<<"Transaction destroyed\n";
}

std::string displayEnum(TRANSACTION_TYPE type)
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