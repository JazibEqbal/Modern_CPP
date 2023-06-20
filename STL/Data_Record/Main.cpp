#include "functionalities.h"
#include "Data.h"
#include<iostream>
#include<algorithm>
#include<functional>
#include<numeric>
#include<memory>
#include<array>
#include<unordered_map>
#include<future>

using Pointer = std::shared_ptr<Data>;
using Conatiner = std::array<Pointer,9>;

void Call(Conatiner &data){
    createDataRecords(data);
    averageApplicantIncome(data);
    countByMaritalStatus(data);
    numberOfAcceptedApplications(data);
    ApplicantCountByGender(data);
    ApplicantByPropoertyArea(data);
    HighestLoanAmountAccepted(data);
    MarriedApplicationRatio(data);
}
void Async(std::future<Conatiner&> &fu){ //refernce of a conatiner stored in a ref of object
    std::cout<<"Thread Started\n\n";

    Conatiner data =fu.get();

    std::cout<<"Async calling...\n\n";
    createDataRecords(data);
    averageApplicantIncome(data);
    countByMaritalStatus(data);
    numberOfAcceptedApplications(data);
    ApplicantCountByGender(data);
    ApplicantByPropoertyArea(data);
    HighestLoanAmountAccepted(data);
    MarriedApplicationRatio(data);
}

int main(){
    Conatiner data;
    Call(data);

    std::promise<Conatiner&> pr;
    std::future<Conatiner&> ft = pr.get_future();

    std::future<void> res = std::async(std::launch::async,&Async, std::ref(ft));

    std::this_thread::sleep_for(std::chrono::seconds(5));

    Conatiner data2;
    pr.set_value(std::ref(data2));
}
/*
    launch async means creating a separate new thread
    launch deferred means no new thread will be created and 
    task will be completed concurrently on the same thread.
*/