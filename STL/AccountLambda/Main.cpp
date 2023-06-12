#include "Account.h"
#include "Transaction.h"
#include <optional>
#include <functional>
#include <algorithm>
#include <iostream>
#include <list>
#include "functionalities.h"


int main() {
    // Create a list of Account instances
    std::list<Account> accounts;

    // Create transactions for account 1
    std::vector<Transaction> transactions1;
    transactions1.emplace_back(100.0, "Receipt1", "NETBANKING");
    transactions1.emplace_back(200.0, "Receipt2", "UPI");
    transactions1.emplace_back(300.0, "Receipt3", "RTGS");

    // Create an account with the transactions
    Account account1("A12345", 1000.0, ACCOUNT_TYPE::SAVINGS, "John Doe", transactions1);

    // Add account1 to the accounts list
    accounts.push_back(account1);

    // Create transactions for account 2
    std::vector<Transaction> transactions2;
    transactions2.emplace_back(500.0, "Receipt4", "NEFT");
    transactions2.emplace_back(600.0, "Receipt5", "UPI");

    // Create an account with the transactions
    Account account2("B67890", 2000.0, ACCOUNT_TYPE::CURRENT, "Jane Smith", transactions2);
    accounts.push_back(account2);

    // Create transactions for account 3
    std::vector<Transaction> transactions3;
    transactions3.emplace_back(700.0, "Receipt6", "RTGS");
    transactions3.emplace_back(800.0, "Receipt7", "NEFT");

    // Create an account with the transactions
    Account account3("C24680", 3000.0, ACCOUNT_TYPE::SAVINGS, "Bob Johnson", transactions3);
    accounts.push_back(account3);

    // Create a list of lambdas (functions)
    std::list<std::function<float(const std::list<Account>&)>> functions;
    functions.push_back(findAccountBalanceWithHighestTotalTransactionAmountLambda);
    functions.push_back(findHighestTransactionAmountLambda);

    // Call the operation function to map the lambdas on the data container (list of accounts)
    operation(accounts, functions);

    return 0;

}

    // //std::cout << HighestBalanceAmount(acc) << "\n";
    // //std::cout << HighestTransactionAmount(acc) << "\n";
    // std::list<std::function<float(std::list<Account*> &v)>> fun = {HighestBalanceAmount,HighestTransactionAmount};
    // //std::list<std::function<float(std::list<Transaction*> &v)>> fun2 = {HighestTransactionAmount};

    // operation(acc,fun);
    //operation2(t,fun2);