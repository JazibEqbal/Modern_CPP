#include "Account.h"

Account::Account(std::string holderName, float balance, ACCOUNT_TYPE type, DebitCard* card)
: accountHolderName(holderName),accountBalance(balance),accountType(type),accountDebitCard(card) {}

Account::~Account()
{
    std::cout<<"Account\n";
}

std::ostream &operator<<(std::ostream &os, const Account &rhs) {
    os << "accountHolderName: " << rhs.accountHolderName
       << " accountBalance: " << rhs.accountBalance
       << " accountType: " << displayEnumForAccount(rhs.accountType)
       << " accountDebitCard: " << rhs.accountDebitCard->getDebitCardNumber() 
       <<" " << rhs.accountDebitCard->getDebitCardCVV();

    //    for(auto* it : rhs.accountDebitCard){
    //         os << it->
    //    }
    return os;
}


std::string displayEnumForAccount(enum class ACCOUNT_TYPE accType){
    if(accType == ACCOUNT_TYPE::CURRENT){
        return "CURRENT";
    } else if(accType == ACCOUNT_TYPE::SALARY){
        return "SALARY";
    } else{
        return "SAVINGS";
    }
}