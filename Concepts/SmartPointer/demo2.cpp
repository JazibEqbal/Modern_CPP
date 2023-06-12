#include<iostream>
#include<memory>
#include<list>
#include<algorithm>

using DataContainer  = std::list<std::unique_ptr<Class_name>>;

void EmplaceEmployee(DataContainer &data){
    data.emplace_back(std::make_unique<Class_name>(1,2));
    data.emplace_back(std::make_unique<Class_name>(1,2));
    data.emplace_back(std::make_unique<Class_name>(1,2));
}

// auto FindEmployeeId = [](DataContainer &data){
//     int max = 0;
//     auto id = data.front().getEmployeeId();
//     for(auto &it: data){
//         if(it->getSalary() > max){
//             max = it->getSalary();
//             id = it->getEmployeeId();
//         }
//     }
//     return id;
// }

int findEmployeeId(DataContainer &data){
    auto itr = std::max_element(
        data.begin(),
        data.end(),
        [](auto &obj1,auto &obj2){
            return obj1->getSalary() < obj2->getSalary(); //a comperator
        }
    );
    return (*itr)->getEmployeedId(); //de referencing the pointer where max element is and getting its id
}

int main(){
    DataContainer data;
    EmplaceEmployee(data);
}