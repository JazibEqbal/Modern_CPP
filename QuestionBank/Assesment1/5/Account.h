#ifndef ACCOUNT_H
#define ACCOUNT_H
#include<iostream>
#include "DebitCard.h"
#include "AccountType.h"
class Account
{
private:
    std::string accountHolderName;
    float accountBalance;
    enum class ACCOUNT_TYPE accountType;
    DebitCard* accountDebitCard;
public:
    Account() = delete;
    Account(const Account &obj) = delete;
    Account(std::string holderName, float balance, ACCOUNT_TYPE type ,DebitCard* card);
    ~Account();

    std::string getAccountHolderName() const { return accountHolderName; }
    void setAccountHolderName(const std::string &accountHolderName_) { accountHolderName = accountHolderName_; }

    float getAccountBalance() const { return accountBalance; }
    void setAccountBalance(float accountBalance_) { accountBalance = accountBalance_; }

    enum class ACCOUNT_TYPE accType() const { return accountType;};

    DebitCard* getAccountDebitCard() const { return accountDebitCard; }
    void setAccountDebitCard(DebitCard* accountDebitCard_) { accountDebitCard = accountDebitCard_; }

    friend std::ostream &operator<<(std::ostream &os, const Account &rhs);

};

std::string displayEnumForAccount(enum class ACCOUNT_TYPE accType);

#endif // ACCOUNT_H
