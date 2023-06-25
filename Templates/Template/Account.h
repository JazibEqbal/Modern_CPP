#ifndef ACCOUNT_H
#define ACCOUNT_H
#include<iostream>
#include<functional>
#include<memory>
#include<vector>
#include "Transaction.h"
#include<variant>

template <typename T,typename U>
using wrappertransaction =std::reference_wrapper<std::vector<std::shared_ptr<Transaction<T,U>>>>;

template <typename T,typename U>
class Account
{
private:
    T accountId;
    wrappertransaction<T,U> accountTransactionSet;
    float accountBalance; 
public:
    Account() = delete;
    Account(const Account&) = default;
    Account(T id, wrappertransaction<T,U> set, float balance);
    ~Account();

    T getAccountId() const { return accountId; }
    void setAccountId(const T &accountId_) { accountId = accountId_; }

    wrappertransaction<T,U> getAccountTransactionSet() const { return accountTransactionSet; }
    void setAccountTransactionSet(const wrappertransaction<T,U> &accountTransactionSet_) { accountTransactionSet = accountTransactionSet_; }

    float getAccountBalance() const { return accountBalance; }
    void setAccountBalance(float accountBalance_) { accountBalance = accountBalance_; }

    template <typename A,typename B>
    friend std::ostream &operator<<(std::ostream &os, const Account<A, B> &rhs) {
        os << "accountId: " << rhs.accountId
           << " accountTransactionSet: " << rhs.accountTransactionSet
           << " accountBalance: " << rhs.accountBalance;
        return os;
    }
};


#endif // ACCOUNT_H