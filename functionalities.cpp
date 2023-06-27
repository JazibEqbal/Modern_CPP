#include "functionalities.h"

using DataPointer=std::shared_ptr<Data>;
using container=std::list<DataPointer>;

/*
        Calculate Average loan amount
        first store in sum variable
        then divide by data size.
*/

void AverageLoanAmount(container& data){
    if(data.empty()){
        throw std::runtime_error("Data is void!\n");    // checking exceptions
    }
    float sum;
    sum=std::accumulate(data.begin(),data.end(),0.0f,[](float value,DataPointer& d){
        return value+d->loanAmnt();
    });
    int cnt=data.size();
    std::cout<<"Average Loan Amount : "<<sum/cnt<<"\n";
}

/*
    Showing list of loan intensions which are unique
    print list of Loan intent enums
*/

void ShowUniqueLoanIntensions(container& data){
    if(data.empty()){
        throw std::runtime_error("Data is void!\n");    // checking exceptions
    }
    std::set<LoanIntent> LoanIntentUniqueList;
    std::for_each(data.begin(),data.end(),[&](DataPointer& d){
        LoanIntent l=d->getLoanIntent();
        LoanIntentUniqueList.insert(l);
    });
    std::for_each(LoanIntentUniqueList.begin(),LoanIntentUniqueList.end(),[](LoanIntent loan){
        std::cout<<DisplayIntent(loan)<<"\n";
    });
}

/*
    Highest Interest Rate for accepted loans
    first store value in max rate 
    then print
*/


void HighestInterestRateForAcceptedLoans(container& data){
    if(data.empty()){
        throw std::runtime_error("Data is void!\n");    // checking exceptions
    }
    std::unordered_map<bool,float> maps;
    auto itr=std::max_element(data.begin(),data.end(),[](DataPointer& d1,DataPointer& d2){
        if(d1->loanStatus()==true){
            return d1->loanIntRate() < d2->loanIntRate();
        }
    });
    maps[true]=(*itr)->loanIntRate();
    std::cout<<"Highest Accepted Rate :"<<maps[true]<<"\n";
}

/*
    Print Minimum and maximum ages of customers
*/

void MinMaxAge(container& data){
    if(data.empty()){
        throw std::runtime_error("Data is void!\n");    // checking exceptions
    }
    auto max=std::max_element(data.begin(),data.end(),[](DataPointer& d1,DataPointer& d2){
        return d1->personAge() < d2->personAge();
    });
    auto min=std::min_element(data.begin(),data.end(),[](DataPointer& d1,DataPointer& d2){
        return d1->personAge() > d2->personAge();
    });

    std::cout<<"Max age : "<<(*max)->personAge();
    std::cout<<"\nMin age : "<<(*min)->personAge()<<"\n";
}

/*
       Display Person objects whose data satify condition given .
          1. LOan amount greater than 30000
          2. Loan status is approved
          3. Person age is greater than 30
*/

std::function<std::optional<container>(container&)> SatisfyConditions=[](container& data){
    if(data.empty()){
        throw std::runtime_error("Data is void!\n");    // checking exceptions
    }
    container NewList(data.size());
    auto itr=std::copy_if(data.begin(),data.end(),NewList.begin(),[](DataPointer& a){
        return a->loanAmnt()>30000 && a->loanStatus()==true && a->personAge()>23;
    });
    NewList.resize( std::distance(NewList.begin(),itr) );
    if(NewList.size()==0){
        return container{};
    }
    return NewList;
};

/*
     Average rate print 
     Matching value
     return blank list if not there.
*/

std::function<std::optional<float>(container&,LoanIntent)> AverageRateForMatchingValue=[](container& data,LoanIntent value){
    if(data.empty()){
        throw std::runtime_error("Data is void!\n");    // checking exceptions
    }
    float sum=0.0f;
    int cnt=0;
    for(auto& a:data){
        if(a->getLoanIntent()==value){
            sum+=a->loanIntRate();
            cnt++;
        }
    }
    if(sum==0.0f){
        return float{};
    }
    else{
        return sum/cnt;
    }
};