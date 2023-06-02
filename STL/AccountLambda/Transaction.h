#ifndef TRANSACTION_H
#define TRANSACTION_H
#include<iostream>
#include "TransactionType.h"

class Transaction
{
private:
    float transactionAmount;
    std::string transactionReceiptName;
    enum class TRANSACTION_TYPE transactionType;
public:
    Transaction() = delete;
    Transaction(const Transaction &obj) = default;
    Transaction(float amount,std::string receipt,enum class TRANSACTION_TYPE type);
    ~Transaction();

    float getTransactionAmount() const { return transactionAmount; }
    void setTransactionAmount(float transactionAmount_) { transactionAmount = transactionAmount_; }

    std::string getTransactionReceiptName() const { return transactionReceiptName; }
    void setTransactionReceiptName(const std::string &transactionReceiptName_) { transactionReceiptName = transactionReceiptName_; }

    enum class TRANSACTION_TYPE getTransactionType() const {return transactionType;};

    friend std::ostream &operator<<(std::ostream &os, const Transaction &rhs);
};

std::string displayTransaction(enum class TRANSACTION_TYPE type);
#endif // TRANSACTION_H
