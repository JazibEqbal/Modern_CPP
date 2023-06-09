#include "Account.h"
#include "Transaction.h"
#include <optional>
#include <functional>
#include <algorithm>
#include <iostream>
#include <list>
#include "functionalities.h"

auto HighestBalanceAmount = [](std::list<Account *> &data)
{
    float max = INT16_MIN;
    std::vector<float> vector;
    for(auto *it: data){
        float total=0;
        total += it->getAccountLast5Transactions()->getTransactionAmount();
        vector.push_back(it->getAccountLast5Transactions()->getTransactionAmount());
    }
    // for(auto &it: vector){
    //     int max = 0;
    // }
    float maxTransactionAmount = *std::max_element(vector.begin(),vector.end());
    for(auto *it: data){
        if(it->getAccountLast5Transactions()->getTransactionAmount() == maxTransactionAmount){
            max = it->getAccountBalance();
        }
    }
    return max;
};

// std::function<float(std::list<Account*>&obj)> funcname = [];


auto HighestTransactionAmount = [](std::list<Account *> acc)
{
    float max = INT16_MIN;
    for (auto *it : acc)
    {
        if(it->getTransactionAmount() > max)
            max = it->getTransactionAmount();
    }
    return max;
};

int main()
{
    Transaction *t1 = new Transaction(10.5f, "Main", TRANSACTION_TYPE::NET_BANKING);
    Transaction *t2 = new Transaction(1.5f, "Halo", TRANSACTION_TYPE::NEFT);
    Transaction *t3 = new Transaction(25.5f, "jhj", TRANSACTION_TYPE::RTGS);
    Transaction *t4 = new Transaction(33.5f, "Bolo", TRANSACTION_TYPE::UPI);


    Transaction *trans1[5] = {t1,t2,t3,t4};
    Transaction *trans2[2] = {t3,t4};
    std::list<Transaction*> t = {t1,t2,t3,t4};

    Account *a1 = new Account("22", 323.5f, ACCOUNT_TYPE::CURRENT, "SBI", *trans1);
    Account *a2 = new Account("2", 123.5f, ACCOUNT_TYPE::SAVINGS, "BOB", *trans2);

    std::list<Account *> acc = {a1,a2};

    //std::cout << HighestBalanceAmount(acc) << "\n";
    //std::cout << HighestTransactionAmount(acc) << "\n";
    std::list<std::function<float(std::list<Account*> &v)>> fun = {HighestBalanceAmount,HighestTransactionAmount};
    //std::list<std::function<float(std::list<Transaction*> &v)>> fun2 = {HighestTransactionAmount};

    operation(acc,fun);
    //operation2(t,fun2);
    return 0;
}