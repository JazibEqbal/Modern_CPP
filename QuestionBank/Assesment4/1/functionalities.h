#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H
#include "Person.h"
#include "LoanIntent.h"
#include<iostream>
#include<algorithm>
#include<functional>
#include<vector>
#include<unordered_map>
#include<memory>
#include<optional>
#include<numeric>

using Pointer = std::shared_ptr<Person>; //shared pointer to object
using Conatiner = std::vector<Pointer>;  //creating vector of pointer objects

//function to create objects for data set
extern std::function<void(Conatiner&) > createEnteries;

//function to find average loan amount for all values of data set
extern std::function<void(Conatiner&) > AverageLoanAmount;

//function to show unique categorical data for a set
extern std::function<void(Conatiner&) > ShowUniqueLoanIntentions;

//function to show highest interest rate for accepted loans
extern std::function<void(Conatiner &) > HighestInterestRateForAcceptedLoans;

//function to find highest &lowest age in entire data set
extern std::function<void(Conatiner &) > MinMaxAge;

//function to check eligibility based on given conditions
extern std::function<std::optional<Conatiner>(Conatiner &) > checkEligibility;

//function to find average of interest rate for all set where it matches with givenintent type
extern std::function<float(Conatiner&, INTENT_TYPE) > matchingLoanIntent;

#endif // FUNCTIONALITIES_H
