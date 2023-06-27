#include "Person.h"
#include "LoanIntent.h"
#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <unordered_map>
#include <memory>
#include "functionalities.h"

using Pointer = std::shared_ptr<Person>; // shared pointer to object
using Conatiner = std::vector<Pointer>;  // creating vector of pointer objects

int main()
{
    Conatiner data;
    // calling functions
    createEnteries(data);
    AverageLoanAmount(data);
    ShowUniqueLoanIntentions(data);
    HighestInterestRateForAcceptedLoans(data);
    MinMaxAge(data);

    auto ans = checkEligibility(data);
    if (ans.has_value())
    {
        for (auto &it : ans.value())
        {
            std::cout << *it << "\n";
        }
    }
    else
    {
        std::cout << "No values found\n";
    }

    matchingLoanIntent(data, INTENT_TYPE::EDUCATION);
}