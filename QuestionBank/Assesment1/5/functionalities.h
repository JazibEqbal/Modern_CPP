#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H
#include "Account.h"
#include "Bank.h"
#include "DebitCard.h"
#include<list>

bool FindAccountByDebitCardNumber(std::list<Account *> &acc, unsigned long long debitNumber);

float FindHighestAccountBalance(std::list<Account *> &acc);

int FindCountOfAccountBelowThreshold(std::list<Account *> &acc, float amount);


#endif // FUNCTIONALITIES_H
