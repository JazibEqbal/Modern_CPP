#include "Transaction.h"

Transaction::Transaction(float amount, std::string receipt, TRANSACTION_TYPE type)
    : transactionAmount{amount}, transactionReceiptName{receipt}, transactionType{type} {}

Transaction::~Transaction()
{
    std::cout<<"Transaction destroyed\n";
}

std::ostream &operator<<(std::ostream &os, const Transaction &rhs) {
    os << "transactionAmount: " << rhs.transactionAmount
       << " transactionReceiptName: " << rhs.transactionReceiptName
       << " transactionType: " <<displayTransaction(rhs.transactionType);
    return os;
}

std::string displayTransaction(enum class TRANSACTION_TYPE type){
    if(type == TRANSACTION_TYPE::NET_BANKING){
        return "NET_BANKING";
    } else if(type == TRANSACTION_TYPE::NEFT){
        return "NEFT";
    } else if(type == TRANSACTION_TYPE::RTGS){
        return "RTGS";
    } else {
        return "UPI";
    }
}