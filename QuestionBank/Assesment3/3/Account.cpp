#include "Account.h"

Account::Account(myAccountVariant id, wrappertransaction trans, float balance)
    : accountId{id}, accountTransactionSet{trans}, accountBalance{balance} {}

Account::~Account()
{
    std::cout << "Account destroyed\n";
}

std::ostream &operator<<(std::ostream &os, const Account &rhs)
{
    os << " Account Id: ";
    std::visit([&](auto arg)
               { os << arg; },
               rhs.accountId);
    os << " accountTransactionSet: ";
    for (auto &it : rhs.accountTransactionSet.get())
    {
        os << *it << " "; //
    }
    os << " accountBalance: " << rhs.accountBalance;
    return os;
}
