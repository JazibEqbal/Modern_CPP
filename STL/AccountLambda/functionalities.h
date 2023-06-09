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
