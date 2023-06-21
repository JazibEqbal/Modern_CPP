#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H
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
#include "Accout.h"
#include "Trasaction.h"
#include "TransactionTypeee.h"

using myTransactionpointer = std::shared_ptr<Trasaction>;
using containerTransaction  = std::vector<myTransactionpointer>;

using myAccountpointer = std::shared_ptr<Accout>;

using myAccountpointer = std::shared_ptr<Accout>;

using accVariant = std::variant<int,std::string>;

extern std::function<int(containerTransaction, enum class TRANSACTION_TYPE) > getTheCountOfMatchingTransactionType;

extern std::function<float(containerTransaction &data) > getTotalOfTransactionAmount;

extern std::function<int(containerTransaction, enum class TRANSACTION_TYPE) > getTheCountOfMatchingTransactionType;


#endif // FUNCTIONALITIES_H
