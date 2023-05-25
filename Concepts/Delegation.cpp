#include<iostream>
#include<unordered_map>

using myMap =  std::unordered_map<int, Delegation>;  //using is alias of typedef

class Delegation
{
private:
    int studentId;
    std::string studentName;
    float studentFees;
public:
    Delegation() = delete;
    //1 arg constructor
    explicit Delegation(int id) : studentId{id} {}
    //2 arg constructor with delegation
    Delegation(int id,std::string name) : Delegation(id) {
        this->studentName=name;
    }
    // 3 arg constructor
    Delegation(int id,std::string name,float fees) : studentId{id}, studentName{name},studentFees{fees} {}
    //Delegating way
    Delegation(int id,std::string name,float fees) : Delegation(id,name) {
        this->studentFees = fees;
    }
    ~Delegation() {
        std::cout<<"des called\n";
    }
};

int main(){
    auto data = myMap{1,2,3};
    return 0;
}

/*
trailing return
auto square(int num) -> int {
    return num*num;
}
*/