#ifndef TRASACTION_H
#define TRASACTION_H
#include<iostream>
#include<variant>
#include "TransactionTypeee.h"

using myVariant = std::variant<int,std::string>;

class Trasaction
{
private:
    myVariant transactionId;
    float transactionAmount;
    TRANSACTION_TYPE transactionType;
public:
    Trasaction() = delete;
    Trasaction(const Trasaction&) = default;
    Trasaction(myVariant id,float amount,TRANSACTION_TYPE type);
    ~Trasaction();

    myVariant getTransactionId() const { return transactionId; }
    void setTransactionId(const myVariant &transactionId_) { transactionId = transactionId_; }

    float getTransactionAmount() const { return transactionAmount; }
    void setTransactionAmount(float transactionAmount_) { transactionAmount = transactionAmount_; }

    TRANSACTION_TYPE getTransactionType() const { return transactionType;};

    friend std::ostream &operator<<(std::ostream &os, const Trasaction &rhs);
};
std::string displayEnum(enum class TRANSACTION_TYPE type);

#endif // TRASACTION_H
