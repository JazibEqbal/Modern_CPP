#include "functionalities.h"
#include "Person.h"
#include "LoanIntent.h"
#include<iostream>
#include<algorithm>
#include<functional>
#include<vector>
#include<unordered_map>
#include<memory>
#include<numeric>
#include<list>
#include<set>

using Pointer = std::shared_ptr<Person>; //shared pointer to object
using Conatiner = std::vector<Pointer>;  //creating vector of pointer objects

//creating vector of objects
std::function<void(Conatiner &) > createEnteries = [](Conatiner &data){
    data.emplace_back(std::make_shared<Person>(22,59000,INTENT_TYPE::PERSONAL,35000,16.02f,true));
    data.emplace_back(std::make_shared<Person>(25,9600,INTENT_TYPE::MEDICAL,5500,12.87f,true));
    data.emplace_back(std::make_shared<Person>(23,65500,INTENT_TYPE::MEDICAL,35000,15.23f,true));
    data.emplace_back(std::make_shared<Person>(24,54400,INTENT_TYPE::MEDICAL,35000,14.27f,true));
    data.emplace_back(std::make_shared<Person>(21,9900,INTENT_TYPE::VENTURE,2500,7.14f,true));
    data.emplace_back(std::make_shared<Person>(26,77100,INTENT_TYPE::EDUCATION,35000,12.42f,true));
    data.emplace_back(std::make_shared<Person>(24,78956,INTENT_TYPE::MEDICAL,35000,11.11f,true));
    data.emplace_back(std::make_shared<Person>(24,83000,INTENT_TYPE::PERSONAL,35000,8.9f,true));
    data.emplace_back(std::make_shared<Person>(21,10000,INTENT_TYPE::VENTURE,1600,14.74f,true));
    data.emplace_back(std::make_shared<Person>(22,85000,INTENT_TYPE::VENTURE,35000,10.37f,true));
};

/*
    - checking if passed set is empty or not, if empty throwing error
    - adding loan amount to amount for all objects
    - finally returning the total
*/
std::function<void(Conatiner &) > AverageLoanAmount = [](Conatiner &data){
    if (data.empty()) // checking exception if list passed is empty
    {
        throw std::runtime_error("List passed is empty");
    }
    int amount=0;
    amount = std::accumulate(data.begin(),data.end(),0,[](float val,Pointer &obj){
        return val + obj->loanAmnt();
    });
    std::cout<<"Average Loan Amount for entire dataset is: "<<amount/data.size()<<"\n"; //displaying here
};

/*
    - checking if passed set is empty or not, if empty throwing error
    - creating vector of INTENT TYPE
    - transforming only intent value into vector called v
    - sorting the vector 
    - then apllying std::unique to find only unique INTENT TYPE values and removing dupliates
    - finally returning the unique list
*/
std::function<void(Conatiner &) > ShowUniqueLoanIntentions = [](Conatiner &data){
    if (data.empty()) // checking exception if list passed is empty
    {
        throw std::runtime_error("List passed is empty");
    }
    std::set<INTENT_TYPE> set;
    std::for_each(data.begin(),data.end(),[&](Pointer& d){
        INTENT_TYPE l=d->getIntent();
        set.insert(l);
    });
    std::for_each(set.begin(),set.end(),[](INTENT_TYPE obj){
        std::cout<<displayLoanIntent(obj)<<"\n";
    });
};
/*
    - checking if passed set is empty or not, if empty throwing error
    - finding the max element 
    - finally returning the interestrate where itr is pointing which is at max element
*/
std::function<void(Conatiner &) > HighestInterestRateForAcceptedLoans = [](Conatiner &data){
    if (data.empty()) // checking exception if list passed is empty
    {
        throw std::runtime_error("List passed is empty");
    }
    auto itr = std::max_element(data.begin(),data.end(),[](Pointer &obj1, Pointer &obj2){
        return obj1->loanIntRate() < obj2->loanIntRate() && (obj1->isLoanStatus() && obj2->isLoanStatus());
    });

    std::cout<<"Highest loan rate: "<<(*itr)->loanIntRate()<<"\n";
};
    // std::unordered_map<bool,float> maps;
    // auto itr=std::max_element(data.begin(),data.end(),[](DataPointer& d1,DataPointer& d2){
    //     if(d1->loanStatus()==true){
    //         return d1->loanIntRate() < d2->loanIntRate();
    //     }
    // });
    // maps[true]=(*itr)->loanIntRate();
    // std::cout<<"Highest Accepted Rate :"<<maps[true]<<"\n";
/*
    - checking if passed set is empty or not, if empty throwing error
    - finding min_element from the entire dataset on age
    - finding max_element from the entire dataset on age
    - finally displaying both min and max age
*/
std::function<void(Conatiner &) > MinMaxAge = [](Conatiner &data){
    if (data.empty()) // checking exception if list passed is empty
    {
        throw std::runtime_error("List passed is empty");
    }
    auto minAge = std::min_element(data.begin(),data.end(),[](Pointer &obj1,Pointer &obj2){
        return obj1->personAge() < obj2->personAge();
    });

    auto maxAge = std::max_element(data.begin(),data.end(),[](Pointer &obj1,Pointer &obj2){
        return obj1->personAge() < obj2->personAge();
    });

    std::cout<<(*minAge)->personAge()<<"\n";
    std::cout<<(*maxAge)->personAge()<<"\n";
    //OTHER WAY
    // auto itr = std::minmax_element(data.begin(), data.end(), [](Pointer &obj1, Pointer &obj2)
    //                                { return obj1->personAge() < obj2->personAge(); });
    // std::cout << (*itr.first)->personAge() << " " << (*itr.second)->personAge() << " \n";
};

/*
    - checking if passed set is empty or not, if empty throwing error
    - creating a container of size of data
    - copying data into container based on satisfied criteria
    - resizing the container
    - check if container size is still 0 or above, if 0 returning empty container else the container of objects
*/
std::function<std::optional<Conatiner>(Conatiner &) > checkEligibility = [](Conatiner &data){
    if (data.empty()) // checking exception if list passed is empty
    {
        throw std::runtime_error("List passed is empty");
    }
    Conatiner container(data.size());
    auto itr = std::copy_if(data.begin(),data.end(),container.begin(),[](Pointer &obj){
        return obj->loanAmnt() > 30000 && obj->isLoanStatus() && obj->personAge() > 23;
    });
    container.resize(std::distance(container.begin(),itr));
    if(container.size() == 0){
        return Conatiner();
    }else{
        return container;
    }
};

/*
    - checking if passed set is empty or not, if empty throwing error
    - creating list of float values to store interest rate which is also of type float of size of data.
    - emplacing the loan interest rate into the list if it matches with the INTENT Type passed
    - resizing the list
    - applying accumulate to find total of interest rate 
    - finally returning the average by diving total/size of list.
*/

std::function<float(Conatiner&, INTENT_TYPE) > matchingLoanIntent = [](Conatiner& data, INTENT_TYPE type){
    if (data.empty()) // checking exception if list passed is empty
    {
        throw std::runtime_error("List passed is empty");
    }
    std::list<Pointer> list(data.size());

    auto itr = std::copy_if(data.begin(),data.end(),list.begin(),[&](Pointer &obj){
        return obj->loanIntRate() && obj->getIntent() == type;
    });
    list.resize(std::distance(list.begin(),itr));
    auto total = std::accumulate(list.begin(),list.end(),0.0f,[](float val, Pointer &obj){
        return val + obj->loanAmnt();
    });
    return total/list.size();
};