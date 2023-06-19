#include<iostream>
#include<numeric>
#include<vector>
#include<algorithm>
#include<memory>
#include "Automobile.h"

using container = std::vector<std::unique_ptr<Automobile>>;
void add(container &data){
    data.emplace_back(std::make_unique<Automobile>(1,"aa",23.0f,2,CAR_CATEGORY::HATCHBACK));
    data.emplace_back(std::make_unique<Automobile>(1,"aa",33.0f,2,CAR_CATEGORY::HATCHBACK));
    data.emplace_back(std::make_unique<Automobile>(1,"aa",43.0f,2,CAR_CATEGORY::HATCHBACK));
    data.emplace_back(std::make_unique<Automobile>(1,"aa",53.0f,2,CAR_CATEGORY::SEDAN));
}

int main(){
    // std::vector<int> v(10);
    // std::iota(v.begin(),v.end(),1); //fill sequential values

    // //copy all data from v1 into a new vector v2 if data value is divisble by 5
    // std::vector<int> v2(v.size());
    // auto itr = std::copy_if(v.begin(),v.end(),v2.begin(),[](int x){
    //     return  x % 5 ==0;
    // });
    // v2.resize(std::distance(v2.begin(),itr));

    // //copy all data from v1 into a new vector v2 if data value is divisble by 4 greater than 5 and less than 10
    // std::copy_if(v.begin(),v.end(),v2.begin(),[](int x){
    //     return  (x % 4 == 0 && 5 < x < 10);
    // });

    // std::max_element(v2.begin(),v2.end()); //returns iterator to max element
    container data;
    add(data);
    //find automobile with the highest price and display its car category
    using object = std::unique_ptr<Automobile>;
    auto itr =std::max_element(data.begin(),data.end(),[](object &obj1,object &obj2){
        return obj1->getCarPrice() < obj2->getCarPrice();
    });
    return (*itr)->getCarCategory();
    //all of
    bool res = std::all_of(data.begin(),data.end(),[](object &obj){
        return obj->getCarPrice() > 50;
    });
    //any of
    bool anyResult = std::any_of(data.begin(),data.end(),[](object &obj){
        return obj->getCarCategory() == CAR_CATEGORY::SEDAN;
    });

    //find registration tax for all objects as 10% of auto mobile price and store all answers in a vector
    //transform applies a given function onto each element of input container range

    std::vector<float> v3(data.size());
    //TRANSFORM
    std::transform(data.begin(),
                        data.end(),
                        v3.begin(),
                        [](object &obj){
                            return obj->getCarPrice() *.1f;
                        }
        );
    //FOR-EACH
    std::for_each(v3.begin(),v3.end(),[](float val){
        std::cout<<"Value is: "<<val<<" ";
    });

    //ADVANCE
    auto itr = data.begin();
    std::advance(itr,3);
    std::for_each(itr,data.end(),[](object &obj){
        std::cout<< displayCarCategory(obj->getCarCategory());
    });
    //SORT
    std::sort(data.begin(),data.end(),[](object &obj1,object &obj2){
        return obj1->getCarPrice() < obj2->getCarPrice();
    });
    std::sort(data.begin(),data.end());
    std::sort(data.begin(),data.end(),std::greater<int>());
}