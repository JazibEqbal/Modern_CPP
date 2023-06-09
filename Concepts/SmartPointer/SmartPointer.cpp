#include<iostream>
#include<memory>

class SmartPointer
{
private:
    int id;
public:
    SmartPointer(int i) : id{i} {}
    ~SmartPointer() {
        std::cout<<"Des\n";
    }
    int getId() const { return id; }
};

void magic_shared(std::shared_ptr<SmartPointer> ptr){
    std::cout<<ptr->getId()<<"\n";
    std::cout<<ptr.use_count()<<"\n";
}

void magic_unique(std::unique_ptr<SmartPointer> &ptr){
    std::cout<<ptr->getId()<<"\n";
}

int main(){
    std::shared_ptr<SmartPointer> ptr = std::make_shared<SmartPointer>(9);
    magic_shared(ptr);

    std::cout<<"In main "<<ptr.use_count()<<"\n";

    ptr.reset(); // deleting ptr manually at any point which I want before the end of scope of main

    std::unique_ptr<SmartPointer> ptr1 = std::make_unique<SmartPointer>(10);
    magic_unique(ptr1);
}
/*
    any resource that a shared pointer is pointing to must be released only when the use count is 0
*/
//one pointer for magic function and other one is from main(2)...once magic goes out of scope and returns back to main
//one shared ptr goes out of scope(from magic fun) and after main goes out of scope destructor is called

/*
    UNIQUE PTR -- 
            cannot be copied
            releases resource(deletes memory) after pointer variables goes out of its scope
                e.g: a unique ptr is declared in function xyz, it will delete its resource at the end of scope

    SHARED PTR
            can be copied multiple times
            releases resource(deletes memory) after all copies of pointer variables goes out of their respective
            function scope i.e whne use count become 0.
            e.g: create a shared ptr in xyz,copy it into abc and copy again in mno.
            resource is released when xyz scope ends(the last function in the call stack which has a copy of pointer)
*/