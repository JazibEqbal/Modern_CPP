#include<iostream>

class elision  //omitting something
{//when it accepts rvalue or return a rvalue
private:
    int id;
    std::string data;
public:
    elision(int i,std::string data) {
        this->id =i;
        this->data=data;
        std::cout<<"Demo cons\n";
    }
    elision(const elision &obj){
        std::cout<<"Copy cons called\n";
    };
    elision(elision &&obj) = default; //move constructor //no const allowed
    ~elision() {}

    int getId() const { return id; }

    std::string getData() const { return data; }
};

elision magic(){
    elision obj1(1,"ja");            // no copy happens as the value is directly stored into the destination address
    elision obj2(std::move(obj1)); //std::move makes a rvalue out of anything that is passed to it
    std::cout<<"Value in obj 2 is "<<obj2.getId()<<"\n";    // that's why copy constructor is best to mark as default
    std::cout<<"Value in obj 1 is "<<obj1.getId()<<" "<<obj1.getData()<<"\n";
}

int main(){
    elision ans = magic();
}
//std::move --moves content of obj1 completely to obj2
//actual data is never transfered from one location to another, just it's refernce changes (like pointer)