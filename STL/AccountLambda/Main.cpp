#include "Account.h"
#include "Transaction.h"
#include <optional>
#include <functional>
#include <algorithm>
#include <iostream>
#include <list>
#include "functionalities.h"

auto HighestAmount = [](std::list<Account *> &data)
{
    int max = INT16_MIN;
    float balance = data.front()->getAccountBalance();

    float transAmount = data.front()->getAccountLast5Transactions().front()->getTransactionAmount();

    // for (auto *it : data)
    // {
    //     if (it->getAccountLast5Transactions().front()->getTransactionAmount() > max)
    //     {
    //         max = it->getAccountLast5Transactions().back()->getTransactionAmount();
    //         balance = it->getAccountBalance();
    //     }
    // }
    return balance;
};

// std::function<float(std::list<Account*>&obj)> funcname = [];


// auto HighestTransactionAmount = [](std::list<Account *> trans)
// {
//     float max = INT16_MIN;
//     for (auto *it : trans)
//     {
//         if(it->getAccountLast5Transactions().)
//         max = it->getAccountLast5Transactions().;
//     }
//     return max;
// };

int main()
{
    Transaction *t1 = new Transaction(231.5f, "Main", TRANSACTION_TYPE::NET_BANKING);
    Transaction *t2 = new Transaction(31.5f, "Halo", TRANSACTION_TYPE::NEFT);
    Transaction *t3 = new Transaction(331.5f, "jhj", TRANSACTION_TYPE::RTGS);

    std::list<Transaction *> trans = {t1, t2, t3};

    Account *a1 = new Account("22", 323.5f, ACCOUNT_TYPE::CURRENT, "SBI", trans);
    Account *a2 = new Account("2", 123.5f, ACCOUNT_TYPE::SAVINGS, "BOB", trans);
    Account *a3 = new Account("122", 23.5f, ACCOUNT_TYPE::CURRENT, "PNB", trans);

    std::list<Account *> acc = {a1, a2, a3};

    //std::cout << HighestAmount(acc) << "\n";
    //std::cout << HighestTransactionAmount(trans) << "\n";
    std::list<std::function<float(std::list<Account*> &v)>> fun = {HighestAmount};

    operation(acc,fun);
    return 0;
}