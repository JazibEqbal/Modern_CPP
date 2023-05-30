#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H
#include "Bank.h"
#include "BankCategory.h"
#include "Account.h"
#include "AccountType.h"
#include "DebitCard.h"

bool FindAccountByDebitCardNumber(std::list<Account*> &acc,unsigned long long debitNumber);

float FindHighestAccountBalance(std::list<Account *> &acc);

int FindCountOfAccountBelowThreshold(std::list<Account *> &acc,float amount);

#endif // FUNCTIONALITIES_H
