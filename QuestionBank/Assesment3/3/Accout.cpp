#include "Accout.h"

Accout::Accout(myAccountVariant id, wrappertransaction trans, float balance)
 : accountId{id}, accountTransactionSet{trans}, accountBalance{balance} {}

Accout::~Accout()
{
    std::cout<<"Account destroyed\n";
}

std::ostream &operator<<(std::ostream &os, const Accout &rhs) {
        os << " Account Id: ";
    std::visit([&](auto arg)
               { os << arg; },
               rhs.accountId);
     os  << " accountTransactionSet: ";
     for(auto &it : rhs.accountTransactionSet){
        os << it.get()->getTransactionAmount()<<" ";
     }
      os << " accountBalance: " << rhs.accountBalance;
    return os;
}
