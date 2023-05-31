#include "Bank.h"
Bank::Bank(std::string name, std::string code, BANK_CATEGORY category, std::list<Account *> &obj)
: bankName{name}, bankIfscCode{code}, bankcategory{category}, bankAccount{obj} {}

Bank::~Bank()
{
    std::cout<<"Bank\n";
}

std::ostream &operator<<(std::ostream &os, const Bank &rhs) {
    os << "bankName: " << rhs.bankName
       << " bankIfscCode: " << rhs.bankIfscCode
       << " bankcategory: " << displayBankcategory(rhs.bankcategory)
        << " bankAccount: ";
       for(auto* it : rhs.bankAccount){     //{b1,b2}
        os << it->getAccountHolderName();
       }
    return os;
}

std::string displayBankcategory(enum class BANK_CATEGORY category){
    if(category == BANK_CATEGORY::COOPERATIVE){
        return "COOPERATIVE";
    } else if(category == BANK_CATEGORY::SEMI_GOVERNMENT){
        return "SEMI_GOVERNMENT";
    } else{
        return "NATIONALIZIED";
    }
}