#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H
#include "Transaction.h"
#include "Account.h"
#include "TransactionType.h"
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

// Transaction
using myTransactionpointer = std::shared_ptr<Transaction>;
using containerTransaction = std::vector<myTransactionpointer>;

// Account
using myAccountpointer = std::shared_ptr<Account>;
using containerAccount = std::vector<myAccountpointer>;

using Variant = std::variant<int, std::string>;

// 1
extern std::function<int(containerTransaction &, std::future<TRANSACTION_TYPE> &)> getTheCountOfMatchingTransactionType;

// 2
extern std::function<float(containerAccount &)> totalTransactionAmount;

// 3
extern std::function<Variant(containerAccount &, TRANSACTION_TYPE)> findMaxAccountBalanceId;

// 4
extern std::function<std::optional<containerAccount>(containerAccount &, float)> accountAboveThreshold;

// 5
extern std::function<Variant(containerAccount &, int, Variant)> nthTransactionId;

// 6
extern std::function<float(containerAccount &, Variant)> averageTransactionAmount;

// 7
extern std::function<float(std::future<containerAccount> &)> balanceInterestAmount;

// 8
extern std::function<bool(myAccountpointer &)> isAccountValid;

#endif // FUNCTIONALITIES_H
