#ifndef ACCOUT_H
#define ACCOUT_H
#include<iostream>
#include<vector>
#include<variant>
#include<functional>
#include "Trasaction.h"
#include<array>
#include<memory>

using myAccountVariant= std::variant<int,std::string>;
using wrappertransaction = std::vector<std::shared_ptr<Trasaction>>;
class Accout
{
private:
    myAccountVariant accountId;
    std::vector<std::shared_ptr<Trasaction>> accountTransactionSet;
    float accountBalance; 
public:
    Accout() = delete;
    Accout(const Accout&) = default;
    Accout(myAccountVariant id, wrappertransaction trans,float balance);
    ~Accout();

    myAccountVariant getAccountId() const { return accountId; }
    void setAccountId(const myAccountVariant &accountId_) { accountId = accountId_; }

    //wrappertransaction getAccountTransactionSet() const { return accountTransactionSet; }
    //void setAccountTransactionSet(const wrappertransaction &accountTransactionSet_) { accountTransactionSet = accountTransactionSet_; }

    float getAccountBalance() const { return accountBalance; }
    void setAccountBalance(float accountBalance_) { accountBalance = accountBalance_; }

    std::vector<std::shared_ptr<Trasaction>> getAccountTransactionSet() const { return accountTransactionSet; }
    void setAccountTransactionSet(const std::vector<std::shared_ptr<Trasaction>> &accountTransactionSet_) { accountTransactionSet = accountTransactionSet_; }

    friend std::ostream &operator<<(std::ostream &os, const Accout &rhs);
};

#endif // ACCOUT_H
