#include "functionalities.h"

bool FindAccountByDebitCardNumber(std::list<Account *> &acc, unsigned long long debitNumber)
{
    for(auto *it: acc){
        if(it->getAccountDebitCard()->getDebitCardNumber() == debitNumber){
            return true;
        }
    }
    return false;
}

float FindHighestAccountBalance(std::list<Account *> &acc)
{
    float max = INT16_MIN;
    for(auto *it: acc){
        max = it->getAccountBalance();
    }
    return max;
}


int FindCountOfAccountBelowThreshold(std::list<Account *> &acc,float amount){
    int count = 0;
    for(auto *it: acc){
        if(it->getAccountBalance() < amount){
            count++;
        }
    }
    return count;
}