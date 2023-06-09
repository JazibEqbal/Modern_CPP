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

int main(){
    int choice =0;
    std::cin>>choice;
    std::weak_ptr<SmartPointer> wkPtr;
    if(choice == 1){
        std::shared_ptr<SmartPointer> ptr = std::make_shared<SmartPointer>(9);
        wkPtr = ptr; //start stalking
        magic_shared(ptr);

        std::cout<<"In main "<<ptr.use_count()<<"\n";

        std::cout<<"inside if: "<<wkPtr.expired()<<"\n"; //boolean 0 or 1
    }
    std::cout<<"outside if: "<<wkPtr.expired()<<"\n"; //confirming if resource is still around
}

//count of weak pointer is not added to count of shared pointer