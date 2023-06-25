#include<iostream>
#include<unordered_map>
#include<memory>
#include<algorithm>
#include<list>
/*
    T.C means the corelation between size of data and no. of operations to be performed.
*/
                                           
using container = std::unordered_map<int,Class_Name>;  //--1
using container = std::unordered_map<int,std::unique_ptr<Class_Name>>; // ---2

//createCOntainer takes one lvalue reference to a standard unordered map of string to Class_Name as its parameter and returns void
void createCOntainer(container &data){
    std::unique_ptr<Class_Name> ptr1 = std::make_unique<Class_Name>(101,200);

    data.insert({("1",*ptr1)}); //sends to make_pair //then copy it into the container //1

    data.emplace(std::make_pair(1,*ptr1)); //works with variables - an lvalue

    //directly passing rvalue to emplace
    data.emplace(1,std::make_unique<Class_Name>(101,200));  //2   2nd arg is a rvalue

    //using make_pair with template parameter
    data.emplace(std::make_pair("a",std::move(ptr1))); //make pair alwasys needs a rvalue
}

void display(container &data){
    for(auto &[k,v]: data){
        std::cout<<"Key:"<<k<<"\tValue: "<<*(v.get())<<"\n"; //v.get().methods of class
    }
}

void printDetails(container &data,std::string key){
    auto itr = data.find(key);
    if(itr == data.end()){
        std::cout<<"No matching found";
    } else{
        auto &[k,v] = *itr;
        std::cout<<*itr<<"\n";
        //other way
        std::cout<<"Key found: "<<*(itr)->second<<"\n";
    }
}

//a function that accepts an unordered map and a list of keys--
//return the total salary for employees whose key is passed in the list

float salaryTotal(conatiner &data,std::list<std::string> keys){
    float sum=0.0f;
    for(auto key: keys){            //looping over list of keys
        if(auto itr = data.find(key); itr !=data.end()){ //if init initializer
            sum += itr->second->getEmployeeSalary();
        }
    }
    return sum;
}

int main(){
container data;
   createCOntainer(data);
    std::pair<int,int> p1 = std::make_pair(1,22);
    auto[key,value] = p1;
    std::cout<<key<<value<<"\n";
    // std::cout<<p1.first;     //old way //iterator way
    // std::cout<<p1.second;
}
