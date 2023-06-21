#include<iostream>
#include<optional>
#include<functional>
#include<algorithm>
#include<vector>
#include<memory>
#include<thread>
#include<future>
#include<thread>
#include "Accout.h"
#include "Trasaction.h"
#include "TransactionTypeee.h"
#include "functionalities.h"
#include<numeric>

using myTransactionpointer = std::shared_ptr<Trasaction>;
using containerTransaction  = std::vector<myTransactionpointer>;

using myAccountpointer = std::shared_ptr<Accout>;

std::function<int(containerTransaction, enum class TRANSACTION_TYPE) > getTheCountOfMatchingTransactionType =
[](containerTransaction &data,enum class TRANSACTION_TYPE type){
    int count = std::count_if(data.begin(),data.end(),[&](myTransactionpointer &obj){
        return obj->getTransactionType() == type;
    });
    return count;
};

std::function<float(containerTransaction &data) > getTotalOfTransactionAmount =
[](containerTransaction &data){
    float total = 0;
    total += std::accumulate(data.begin(),data.end(),0.0f,[](myAccountpointer &obj,float val){
        return val + obj.get()->getAccountTransactionSet()
    })
};

std::function<int(containerTransaction, enum class TRANSACTION_TYPE) > getTheCountOfMatchingTransactionType=
[](containerTransaction &data,TRANSACTION_TYPE type){
    auto itr = std::find_if(data.begin(),data.end(),[](myAccountpointer &obj){
        return obj->getAccountTransactionSet().
    })
};

