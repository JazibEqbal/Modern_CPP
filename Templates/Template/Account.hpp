#include "Account.h"

template <typename T, typename U>
Account<T, U>::Account(T id, wrappertransaction<T, U> set, float balance)
: accountId{id}, accountTransactionSet{set}, accountBalance{balance} {}

template <typename T, typename U>
Account<T, U>::~Account()
{
    std::cout<<"Account destructor\n";
}
