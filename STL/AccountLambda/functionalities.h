#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H
#include "Account.h"
#include "Transaction.h"
#include<optional>
#include<functional>
#include<algorithm>
#include<iostream>

void operation(std::list<Account*> &acc,std::list<std::function<float(std::list<Account*> &v)>> fun);
// void operation2(std::list<Transaction*> &trans,std::list<std::function<float(std::list<Transaction*> &t)>> fun);

#endif // FUNCTIONALITIES_H


void operation(const std::list<Account>& accounts, const std::list<std::function<float(const std::list<Account>&)>>& functions) {
    for (const auto& func : functions) {
        float result = func(accounts);
        std::cout << "Result: " << result << std::endl;
    }
}

