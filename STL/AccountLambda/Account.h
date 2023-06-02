#ifndef ACCOUNT_H
#define ACCOUNT_H
#include<iostream>
#include "AccountType.h"
#include "Transaction.h"
#include<list>
class Account
{
private:
    std::string accountId;
    float accountBalance;
    enum class ACCOUNT_TYPE accountType;
    std::string accountHolderName;
    std::list<Transaction*> accountLast5Transactions;
public:
    Account() = delete;
    Account(const Account &obj) = default;
    Account(std::string id,float balance,enum class ACCOUNT_TYPE type,std::string name,std::list<Transaction*> trans);
    ~Account();

    std::string getAccountId() const { return accountId; }
    void setAccountId(const std::string &accountId_) { accountId = accountId_; }

    float getAccountBalance() const { return accountBalance; }
    void setAccountBalance(float accountBalance_) { accountBalance = accountBalance_; }

    std::string getAccountHolderName() const { return accountHolderName; }
    void setAccountHolderName(const std::string &accountHolderName_) { accountHolderName = accountHolderName_; }

    enum class ACCOUNT_TYPE getAccountType() const {return accountType;};

    std::list<Transaction*> getAccountLast5Transactions() const { return accountLast5Transactions; }
    void setAccountLast5Transactions(const std::list<Transaction*> &accountLast5Transactions_) { accountLast5Transactions = accountLast5Transactions_; }
    
    friend std::ostream &operator<<(std::ostream &os, const Account &rhs);
};

std::string displayEnum(enum class ACCOUNT_TYPE type);
#endif // ACCOUNT_H
