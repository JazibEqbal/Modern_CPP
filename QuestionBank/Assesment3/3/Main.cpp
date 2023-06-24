#include "Transaction.h"
#include "Account.h"
#include "TransactionType.h"
#include "functionalities.h"
#include<iostream>
#include<optional>
#include<functional>
#include<algorithm>
#include<vector>
#include<memory>
#include<thread>
#include<future>
#include<variant>
#include<thread>

using myTransactionpointer = std::shared_ptr<Transaction>;
using containerTransaction  = std::vector<myTransactionpointer>;

using myAccountpointer = std::shared_ptr<Account>;
using containerAccount  = std::vector<myAccountpointer>;

int main(){
    containerTransaction transactions;
    transactions.emplace_back(std::make_shared<Transaction>(1,100.0f,TRANSACTION_TYPE::CARD));
    transactions.emplace_back(std::make_shared<Transaction>(2,200.0f,TRANSACTION_TYPE::CARD));
    transactions.emplace_back(std::make_shared<Transaction>(3,300.0f,TRANSACTION_TYPE::CASH));

    containerAccount account;
    account.emplace_back(std::make_shared<Account>(1,std::ref(transactions),200.0f));
    account.emplace_back(std::make_shared<Account>(2,std::ref(transactions),400.0f));
    account.emplace_back(std::make_shared<Account>(3,std::ref(transactions),600.0f));

    //1
    std::promise<TRANSACTION_TYPE> pr1;
    std::future<TRANSACTION_TYPE> future1 = pr1.get_future();

    std::future<int> r1 = std::async(std::launch::async,getTheCountOfMatchingTransactionType,std::ref(transactions), std::ref(future1));
    auto ans = TRANSACTION_TYPE::CARD;
    pr1.set_value(ans);

    //2
    std::cout<<"Total transaction amount is: "<<totalTransactionAmount(account)<<"\n";

    //3
    auto ans = findMaxAccountBalanceId(account,TRANSACTION_TYPE::CARD);
    //std::visit([](auto &&arg){std::cout<<arg;},ans);

    //4
    auto thresholdAccount = accountAboveThreshold(account,100.0f);
    if(thresholdAccount.has_value()){
        for(auto &it: thresholdAccount.value()){
            std::cout<<*it<<"\n";
        }
    }else{
        std::cout<<"No value is above threshold\n";
    }

    //5
    auto nth = nthTransactionId(account,2,1);
    //std::visit([](auto &&arg){std::cout<<arg;},nth);

    //6
    averageTransactionAmount(account,1);

    //7
    std::promise<containerAccount> pr2;
    std::future<containerAccount> balanceAccounts;
    std::future<float> r3 = std::async(std::launch::async,balanceInterestAmount,std::ref(balanceAccounts));
    pr2.set_value(account);

    //8
    std::shared_ptr<Account> acc1 = std::make_shared<Account>(4,std::ref(transactions),12000.0f);
    std::cout<<isAccountValid(acc1);
}