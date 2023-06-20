#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H
#include "Data.h"
#include<iostream>
#include<algorithm>
#include<functional>
#include<numeric>
#include<memory>
#include<array>

using Pointer = std::shared_ptr<Data>;
using Conatiner = std::array<Pointer,9>;

extern std::function<void(Conatiner &obj) > createDataRecords;

extern std::function<void(Conatiner &data) > averageApplicantIncome;

extern std::function<void(Conatiner &data) > countByMaritalStatus;

extern std::function<void(Conatiner &data)  > numberOfAcceptedApplications;

extern std::function<void(Conatiner &data) > ApplicantCountByGender;

extern std::function<void(Conatiner &data) > ApplicantByPropoertyArea;

extern std::function<void(Conatiner &data) > HighestLoanAmountAccepted;

extern std::function<void(Conatiner &data) > MarriedApplicationRatio;

#endif // FUNCTIONALITIES_H
