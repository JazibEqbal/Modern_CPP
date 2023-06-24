#ifndef ACCOUNT_H
#define ACCOUNT_H
#include "Transaction.h"
#include "TransactionType.h"
#include<iostream>
#include<vector>
#include<variant>
#include<functional>
#include<array>
#include<memory>

using myAccountVariant= std::variant<int,std::string>;
using wrappertransaction =std::reference_wrapper<std::vector<std::shared_ptr<Transaction>>>;
class Account
{
private:
    myAccountVariant accountId;
    wrappertransaction accountTransactionSet;
    float accountBalance; 
public:
    Account() = delete;
    Account(const Account&) = default;
    Account(myAccountVariant id, wrappertransaction trans,float balance);
    ~Account();

    myAccountVariant getAccountId() const { return accountId; }
    void setAccountId(const myAccountVariant &accountId_) { accountId = accountId_; }

    float getAccountBalance() const { return accountBalance; }
    void setAccountBalance(float accountBalance_) { accountBalance = accountBalance_; }

    wrappertransaction getAccountTransactionSet() const { return accountTransactionSet; }
    void setAccountTransactionSet(const wrappertransaction &accountTransactionSet_) { accountTransactionSet = accountTransactionSet_; }

    friend std::ostream &operator<<(std::ostream &os, const Account &rhs);
};

#endif // ACCOUNT_H
