#include<iostream>
#include<memory>
#include<list>

//UNIQUE POINTER
void magic(std::unique_ptr<Class_name> &obj){
    obj.setSalary(2*obj.getSalary());

    std::weak_ptr<Class_name> wk = obj;
    if(wk.expired()) std::cout<<"True";
}

int main(){
    std::unique_ptr<Class_name> ptr = std::make_unique<Class_name>("a",12);

    std::list<std::unique_ptr<Class_name>> list;

    //if data is already present outside the lsit,move it into the list
    list.emplace_back(std::move(ptr));
    //create a new data by using rvalue with emplace back 
    list.emplace_back(ptr); 
    list.emplace_back(std::make_unique<Class_name>("a",12));

    //magic(ptr); dont use this 
    magic(list.front());
}
//SHARED POINTER

/*
    resource: object with data "A",112
    Owner: ptr
    scope: main
*/

void magic(std::shared_ptr<CLass_name> &ptr1){
    //create another pointer that will take joint ownership of this object(ptr1)
    std::shared_ptr<Class_name> ptr2 = ptr1;
    ptr2.setSalary(200);
    std::weak_ptr<Class_name> wk = ptr1;
    if(wk.expired()) std::cout<<"True";
}//ptr2 goes out of scope here

int main(){
    std::shared_ptr<Class_name> ptr = std::make_shared<Class_name>("a",12);
    magic(ptr);
}//ptr goes out of scope here