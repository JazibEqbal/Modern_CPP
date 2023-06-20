#include "functionalities.h"
#include "Data.h"
#include<iostream>
#include<algorithm>
#include<functional>
#include<numeric>
#include<memory>
#include<array>
#include<unordered_map>

using Pointer = std::shared_ptr<Data>;
using Conatiner = std::array<Pointer,9>;

std::function<void(Conatiner &obj) > createDataRecords = [](Conatiner &obj){
    obj[0] = std::make_shared<Data>(1,false,true,false,6608,137,1,true);
    obj[1] = std::make_shared<Data>(2,false,true,false,4444,117,1,true);
    obj[2] = std::make_shared<Data>(3,true,true,true,7780,160,2,true);
    obj[3] = std::make_shared<Data>(4,false,true,false,6608,137,1,true);
    obj[4] = std::make_shared<Data>(5,false,true,true,4000,107,1,false);
    obj[5] = std::make_shared<Data>(6,false,true,false,5608,177,2,true);
    obj[6] = std::make_shared<Data>(7,true,true,false,8708,127,1,true);
    obj[7] = std::make_shared<Data>(8,false,true,false,3408,137,1,true);
    obj[8] = std::make_shared<Data>(9,false,false,false,2000,97,2,false);
};

std::function<void(Conatiner &data) > averageApplicantIncome = [](Conatiner &data){
    float total = 0.0f;

    total = std::accumulate(
        data.begin(),
        data.end(),
        0.0f,
        [](float value, const Pointer &obj){
            return value + obj->getDataApplicantIncome();
        }
    );
    std::cout<<"Average Income is: "<<total/data.size()<<"\n";
};

// std::function<void(Conatiner &data) > countByMaritalStatus = [](Conatiner &obj){
//     int marriedCount;
//     marriedCount = std::count_if(obj.begin(),obj.end(),[](Pointer &p){
//         return p->isDataMaritalStatus();
//     });
//     int unMarried = obj.size() - marriedCount;
//     std::cout<<"Married is:" <<marriedCount<<"\n";
//     std::cout<<"UnMarried is: "<<unMarried<<"\n";
// };

std::function<void(Conatiner &data) > countByMaritalStatus = [](Conatiner &obj) {
    std::unordered_map<bool,int> countMap;
   
    for(bool category: {true,false}){
        countMap[category] = std::count_if(
            obj.begin(),
            obj.end(),
            [&](Pointer &obj){ return obj->isDataMaritalStatus() == category;}
        );
    }
    std::cout<<"Married is: "<<countMap[true]<<"\n";
    std::cout<<"UnMarried is: "<<countMap[false]<<"\n";
    // {true : 7, false: 2}
};

std::function<void(Conatiner &data)  > numberOfAcceptedApplications = [](Conatiner &data){
    std::cout<<"Number Of Accepted Applications is: "<<std::count_if(data.begin(),data.end(),[](Pointer &obj){
        return obj->isDataLoanStatus();
    })<<"\n";
};

std::function<void(Conatiner &data) > ApplicantCountByGender =[](Conatiner &data){
    std::cout<<"Applicant Count By Gender: "<<std::count_if(data.begin(),data.end(),[](Pointer &obj){
        return obj->getDataGender();
    })<<"\n";
};

std::function<void(Conatiner &data) > ApplicantByPropoertyArea = [](Conatiner &data){
    std::unordered_map<bool,int> countMap;
   
    for(bool category: {1,2,3}){
        countMap[category] = std::count_if(
            data.begin(),
            data.end(),
            [&](Pointer &obj){ return obj->getDataPropertyArea() == category;}
        );
    }
    for(auto &[k,v] :countMap){
        std::cout<<"Applicants from area "<< k <<" is: "<<v<<"\n";
    }
};

//1 Way
// std::function<void(Conatiner &data) > HighestLoanAmountAccepted =[](Conatiner &data){
//     float max = 0.0f;
//     for(auto &itr: data){
//         if(float amount = itr->getDataLoanAmount();amount > max && itr->isDataLoanStatus()){
//             max = amount;
//         }
//     }
//     std::cout<<max;
// };

//Other Way
std::function<void(Conatiner &data) > HighestLoanAmountAccepted =[](Conatiner &data){
    std::vector<Pointer> v(data.size());
    auto itr = std::copy_if(data.begin(),data.end(),v.begin(),[](Pointer &p){
        return p->isDataLoanStatus();
    });
    v.resize(std::distance(v.begin(),itr));

    auto res =std::max_element(v.begin(),v.end(),[](Pointer &p1,Pointer &p2){
        return p1->getDataLoanAmount() < p2->getDataLoanAmount();
    });

    std::cout<<"Highest Loan Amount accepted: "<<(*res)->getDataLoanAmount()<<"\n";
};

std::function<void(Conatiner &data) > MarriedApplicationRatio =[](Conatiner &data){
    float marriedCount;
    marriedCount = std::count_if(data.begin(),data.end(),[](Pointer &p){
        return p->isDataMaritalStatus();
    });
    //count -9
    std::unordered_map<bool,int> map;
    for(bool cat : {true}){
        map[cat] = std::count_if(data.begin(),data.end(),[&](Pointer &obj){
            return obj->isDataLoanStatus() == cat && obj->isDataMaritalStatus();
        });
    }
    std::cout<<"Ratio is: "<<marriedCount/map[true]<<"\n";
    //true : 8
};