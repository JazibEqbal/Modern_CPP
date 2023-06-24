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
#include <numeric>
#include <thread>
#include "functionalities.h"

using myTransactionpointer = std::shared_ptr<Transaction>;
using containerTransaction = std::vector<myTransactionpointer>;

using myAccountpointer = std::shared_ptr<Account>;
using containerAccount = std::vector<myAccountpointer>;

using Variant = std::variant<int, std::string>;

std::function<int(containerTransaction &, std::future<TRANSACTION_TYPE> &)> getTheCountOfMatchingTransactionType =
    [](containerTransaction &transactions, std::future<TRANSACTION_TYPE> &fu)
{
    if (transactions.empty())
    {
        throw std::runtime_error("No transactions\n");
    }
    auto type = fu.get();
    int count = std::count_if(transactions.begin(), transactions.end(), [&](myTransactionpointer &obj)
                              { return obj->getTransactionType() == type; });
    return count;
};

std::function<float(containerAccount &)> totalTransactionAmount = [](containerAccount &accounts)
{
    if (accounts.empty())
    {
        throw std::runtime_error("Account list is empty\n");
    }
    float total = 0.0f;
    for (auto &acc : accounts)
    {
        for (auto &transaction : acc->getAccountTransactionSet())
        {
            total += transaction->getTransactionAmount();
        }
    }
    return total;
};

std::function<Variant(containerAccount &, TRANSACTION_TYPE)> findMaxAccountBalanceId =
    [](containerAccount &accounts, TRANSACTION_TYPE type)
{
    if (accounts.empty())
    {
        throw std::runtime_error("Account list is empty\n");
    }
    float maxBalance = 0.0f;
    Variant v;
    for (auto &acc : accounts)
    {
        for (auto &trans : acc->getAccountTransactionSet())
        {
            if (trans->getTransactionType() == type)
            {
                maxBalance = acc->getAccountBalance();
                v = acc->getAccountId();
            }
        }
    }
    return v;
};

std::function<std::optional<containerAccount>(containerAccount &, float)> accountAboveThreshold =
    [](containerAccount &accounts, float threshold)
{
    if (accounts.empty())
    {
        throw std::runtime_error("Account list is empty\n");
    }
    if (threshold < 0)
    {
        throw std::runtime_error("Threshold can't be negative\n");
    }
    containerAccount acc;
    for (auto &ac : accounts)
    {
        float total = 0.0f;
        for (auto &transaction : ac->getAccountTransactionSet())
        {
            total += transaction->getTransactionAmount();
            if (total > threshold)
            {
                acc.emplace_back(ac);
            }
        }
    }
    if (acc.size() == 0)
    {
        return containerAccount();
    }
    else
    {
        return acc;
    }
};

std::function<Variant(containerAccount &, int, Variant)> nthTransactionId =
    [](containerAccount &accounts, int N, Variant v)
{
    if (accounts.empty())
    {
        throw std::runtime_error("Account list is empty\n");
    }
    if (N < 0 || N > accounts.size())
    {
        throw std::runtime_error("Invalid value\n");
    }

    for (auto &it : accounts)
    {
        auto itr = std::next(accounts.begin(), N);
        for (auto &trans : it->getAccountTransactionSet())
        {
            if ((itr)->get()->getAccountId() == v)
            {
                return trans->getTransactionId();
            }
            else
            {
                return Variant();
            }
        }
    }
};

std::function<float(containerAccount &, Variant)> averageTransactionAmount =
    [](containerAccount &accounts, Variant v)
{
    if (accounts.empty())
    {
        throw std::runtime_error("Account list is empty\n");
    }
    float total = 0.0f;
    int count = 0;
    for (auto &acc : accounts)
    {
        for (auto &transaction : acc->getAccountTransactionSet())
        {
            if (acc->getAccountId() == v)
            {
                total += transaction->getTransactionAmount();
                count++;
            }
        }
    }
    return (total / count);
};

std::function<float(std::future<containerAccount> &)> balanceInterestAmount =
    [](std::future<containerAccount> &fu)
{
    float cumulativeInterest = 0.0f;
    auto accounts = fu.get();
    if (accounts.empty())
    {
        throw std::runtime_error("Account list is empty\n");
    }
    for (auto &acc : accounts)
    {
        if (acc->getAccountBalance() > 10000.0f)
        {
            cumulativeInterest += 0.4 * acc->getAccountBalance();
        }
    }
    return cumulativeInterest;
};

std::function<bool(myAccountpointer &)> isAccountValid = [](myAccountpointer &account)
{
    bool isTransactionValid = std::all_of(account->getAccountTransactionSet().begin(), account->getAccountTransactionSet().end(),
                                          [](myTransactionpointer &transaction)
                                          {
                                              return transaction->getTransactionAmount() > 500.0f;
                                          });

    return (account->getAccountBalance() > 10000.0f && account->getAccountTransactionSet().size() >= 3 && isTransactionValid);
};