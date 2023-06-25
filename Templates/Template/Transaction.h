#ifndef TRANSACTION_H
#define TRANSACTION_H
#include<iostream>
#include "TransactionType.h"

template <typename T,typename U>
class Transaction
{
private:
    T transactionId;
    float transactionAmount;
    bool transactionStatus;
    U transactionPlatformId;
    TRANSACTION_TYPE transactionType;
public:
    Transaction() = delete;
    Transaction(const Transaction&) = default;
    Transaction(T id, float amount, bool status, U name, TRANSACTION_TYPE type);
    ~Transaction();

    T getTransactionId() const { return transactionId; }
    void setTransactionId(const T &transactionId_) { transactionId = transactionId_; }

    float getTransactionAmount() const { return transactionAmount; }
    void setTransactionAmount(float transactionAmount_) { transactionAmount = transactionAmount_; }

    bool getTransactionStatus() const { return transactionStatus; }
    void setTransactionStatus(bool transactionStatus_) { transactionStatus = transactionStatus_; }

    TRANSACTION_TYPE getTransactionType() const { return transactionType;};

    U getTransactionPlatformId() const { return transactionPlatformId; }
    void setTransactionPlatformId(const U &transactionPlatformId_) { transactionPlatformId = transactionPlatformId_; }

    template <typename A,typename B>
    friend std::ostream &operator<<(std::ostream &os, const Transaction<A, B> &rhs) {
        os << "transactionId: " << rhs.transactionId
           << " transactionAmount: " << rhs.transactionAmount
           << " transactionStatus: " << rhs.transactionStatus
           << " transactionPlatformId: " << rhs.transactionPlatformId
           << " transactionType: " << rhs.transactionType;
        return os;
    }

};
std::string displayEnum(TRANSACTION_TYPE type);

#endif // TRANSACTION_H
