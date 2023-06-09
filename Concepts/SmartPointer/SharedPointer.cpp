#include<iostream>
#include<list>
#include<memory>

class SharedPointer
{
private:
    int demoId;
public:
    SharedPointer() = default;
    SharedPointer(const SharedPointer &obj) = default;
    SharedPointer(SharedPointer &&obj) = default;
    SharedPointer(int id) : demoId{id}{};
    ~SharedPointer() {
        std::cout<<"Des called "<<this->demoId<<"\n";
    }
    void display(){
        std::cout<<"Display\n";
    }
};

std::list<std::unique_ptr<SharedPointer>> createList(){
    std::list<std::unique_ptr<SharedPointer>> data;
    return data;
}

std::list<std::unique_ptr<SharedPointer>> &addToList(std::list<std::unique_ptr<SharedPointer>> &data){
    data.emplace_back(std::make_unique<SharedPointer>(10));
    data.emplace_back(std::make_unique<SharedPointer>(20));
    data.emplace_back(std::make_unique<SharedPointer>(30));
    data.emplace_back(std::make_unique<SharedPointer>(40));
    data.emplace_back(std::make_unique<SharedPointer>(50));
    return data;
}

void callDisplay(std::list<std::unique_ptr<SharedPointer>> &data){ 
        for(const auto &obj: data){
            obj->display();
    }    
}

int main(){
    
  auto ans = createList();
  addToList(ans);

  callDisplay(ans);
}
