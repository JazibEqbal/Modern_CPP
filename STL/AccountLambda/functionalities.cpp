#include "functionalities.h"

void operation(std::list<Account *> &acc, std::list<std::function<float(std::list<Account*> &v)>> fun)
{
    for(auto &it: fun){
        std::cout<<it(acc)<<"\n";
    }
}
void operation2(std::list<Transaction *> &acc, std::list<std::function<float(std::list<Transaction*> &v)>> fun)
{
    for(auto &it: fun){
        std::cout<<it(acc)<<"\n";
    }
}

std::function<float(const std::list<Account>&)> findAccountBalanceWithHighestTotalTransactionAmountLambda =
    [](const std::list<Account>& accounts) {
        float maxTotalAmount = 0.0;
        float accountBalance = 0.0;
        for (const auto& account : accounts) {
            float totalAmount = 0.0;
            for (const auto& transaction : account.getAccountLast5Transactions()) {
                totalAmount += transaction.getTransactionAmount();
            }
            if (totalAmount > maxTotalAmount) {
                maxTotalAmount = totalAmount;
                accountBalance = account.getAccountBalance();
            }
        }
        return accountBalance;
    };

std::function<float(const std::list<Account>&)> findHighestTransactionAmountLambda =
    [](const std::list<Account>& accounts) {
        float maxTransactionAmount = 0.0;
        for (const auto& account : accounts) {
            for (const auto& transaction : account.getAccountLast5Transactions()) {
                maxTransactionAmount = std::max(maxTransactionAmount, transaction.getTransactionAmount());
            }
        }
        return maxTransactionAmount;
    };