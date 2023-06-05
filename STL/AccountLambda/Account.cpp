#include "Account.h"

Account::Account(std::string id, float balance, ACCOUNT_TYPE type, std::string name,Transaction* trans)
    :accountId{id}, accountBalance{balance}, accountType{type}, accountHolderName{name}, accountLast5Transactions{trans} {}

Account::~Account()
{
    std::cout<<"Account destructor\n";
}

std::ostream &operator<<(std::ostream &os, const Account &rhs) {
    os << "accountId: " << rhs.accountId
       << " accountBalance: " << rhs.accountBalance
       << " accountType: " <<displayEnum(rhs.accountType)
       << " accountHolderName: " << rhs.accountHolderName
       << " accountLast5Transactions: ";
    //    for(auto* it: rhs.accountLast5Transactions){
    //         os<<it<<" ";
    //    }
    while(rhs.getAccountLast5Transactions()){
        os<<rhs.getAccountLast5Transactions()->getTransactionAmount();
    }
    return os;
}

std::string displayEnum(enum class ACCOUNT_TYPE type){
    if(type == ACCOUNT_TYPE::CURRENT){
        return "CURRENT";
    } else {
        return "SAVINGS";
    }
}
