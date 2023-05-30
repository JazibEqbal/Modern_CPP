#ifndef BANK_H
#define BANK_H
#include <iostream>
#include "BankCategory.h"
#include <list>
#include "Account.h"
class Bank
{
private:
    std::string bankName;
    std::string bankIfscCode;
    enum class BANK_CATEGORY bankcategory;
    std::list<Account *> bankAccount;

public:
    Bank() = delete;
    Bank(const Bank &obj) = delete;
    Bank(std::string name, std::string code, enum class BANK_CATEGORY category, std::list<Account *> &obj);
    ~Bank();

    std::string getBankName() const { return bankName; }
    void setBankName(const std::string &bankName_) { bankName = bankName_; }

    std::string getBankIfscCode() const { return bankIfscCode; }
    void setBankIfscCode(const std::string &bankIfscCode_) { bankIfscCode = bankIfscCode_; }

    std::list<Account *> getBankAccount() const { return bankAccount; }
    void setBankAccount(const std::list<Account *> &bankAccount_) { bankAccount = bankAccount_; }

    enum class BANK_CATEGORY getBankCategory() const { return bankcategory; };

    friend std::ostream &operator<<(std::ostream &os, const Bank &rhs);
};
std::string displayBankcategory(enum class BANK_CATEGORY category);

#endif // BANK_H
