#ifndef TRANSACTION_H
#define TRANSACTION_H
#include<iostream>
#include<variant>
#include "TransactionType.h"

using myVariant = std::variant<int,std::string>;

class Transaction
{
private:
    myVariant transactionId;
    float transactionAmount;
    TRANSACTION_TYPE transactionType;
public:
    Transaction() = delete;
    Transaction(const Transaction&) = default;
    Transaction(myVariant id,float amount,TRANSACTION_TYPE type);
    ~Transaction();

    myVariant getTransactionId() const { return transactionId; }
    void setTransactionId(const myVariant &transactionId_) { transactionId = transactionId_; }

    float getTransactionAmount() const { return transactionAmount; }
    void setTransactionAmount(float transactionAmount_) { transactionAmount = transactionAmount_; }

    TRANSACTION_TYPE getTransactionType() const { return transactionType;};

    friend std::ostream &operator<<(std::ostream &os, const Transaction &rhs);
};
std::string displayEnum(enum class TRANSACTION_TYPE type);


#endif // TRANSACTION_H
