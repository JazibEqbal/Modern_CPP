#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H
#include <iostream>
#include <optional>
#include <functional>
#include <algorithm>
#include <vector>
#include <memory>
#include <thread>
#include <future>
#include <variant>
#include <thread>
#include "Account.h"
#include "Transaction.h"
#include "TransactionType.h"

// Transaction
template<typename T,typename U>
using myTransactionpointer = std::shared_ptr<Transaction<T,U>>;

template<typename T,typename U>
using containerTransaction = std::vector<myTransactionpointer<T,U>>;

// Account
template<typename T,typename U>
using myAccountpointer = std::shared_ptr<Account<T,U>>;

template<typename T,typename U>
using containerAccount = std::vector<myAccountpointer<T,U>>;

//1
template<typename T,typename U>
extern std::function<int(containerTransaction<T,U>&,TRANSACTION_TYPE) > getTheCountOfMatchingTransactionType;

#endif // FUNCTIONALITIES_H
