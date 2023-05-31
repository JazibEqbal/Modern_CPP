#include<iostream>
#include<functional>
#include<list>
//think refernces as an alias for a variable
void magic(int &n1){
    std::cout<<"Address of n1 (magic) is: "<<&n1<<"\n";
}

/*
    to create a std::ref wrapper for a value "data" of type T
    1) take the address of the original value called "data"
    2) store this address into a new object called a wrapper object
    Note) this object wrapper object is a copyable & assignable object of type reference_wrapper<T>
*/
int main(){
    int n1=10;
    std::cout<<"Address of n1 (main) is: "<<&n1<<"\n";
    auto data = std::ref<int>(n1);  //std::ref creates a reference wrapper
    std::list<std::reference_wrapper<int>>  values = {data}; // now references can be stored in an list
    std::reference_wrapper<int> arr[1] = {data}; //array ofreferences can now be created

    //magic(data);  //works bcz creates an object that wraps something so it can be referenced

    int n2 = 200;
    data = n2;  //safe reassignment
    auto *ptr = &data; //safe pointer access to wrapper
    // std::cout<<n1<<"\n";
    // std::cout<<data<<"\n";

    return 0;
}

//rvalue cannot be used for std::ref as itis a temporary value
//any funct that does notaccdept a reference can be used with a lvalue reference if we use std::ref(item_name);