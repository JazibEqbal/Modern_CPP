#include<iostream>
#include "Account.h"
#include "Bank.h"
#include "DebitCard.h"
#include <list>
#include "AccountType.h"
#include "BankCategory.h"
#include "functionalities.h"

int main(){
    DebitCard *d1 = new DebitCard(123456789,123);

    std::cout<<d1->getDebitCardCVV(); 
    return 0;
}

