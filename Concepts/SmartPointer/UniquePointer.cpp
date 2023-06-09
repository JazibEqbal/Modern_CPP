#include<iostream>
#include<list>
#include<memory>

class SmartPointers
{
private:
    int demoId;
public:
    SmartPointers() = default;
    SmartPointers(const SmartPointers &obj) = default;
    SmartPointers(SmartPointers &&obj) = default;
    SmartPointers(int id) : demoId{id}{};
    ~SmartPointers() {
        std::cout<<"Des called "<<this->demoId<<"\n";
    }

    void display(){
        std::cout<<"Display\n";
    }
};

std::list<std::unique_ptr<SmartPointers>> createList(){
    std::list<std::unique_ptr<SmartPointers>> data;
    return data;
}

std::list<std::unique_ptr<SmartPointers>> &addToList(std::list<std::unique_ptr<SmartPointers>> &data){
    data.emplace_back(std::make_unique<SmartPointers>(10));
    data.emplace_back(std::make_unique<SmartPointers>(20));
    data.emplace_back(std::make_unique<SmartPointers>(30));
    data.emplace_back(std::make_unique<SmartPointers>(40));
    data.emplace_back(std::make_unique<SmartPointers>(50));
    return data;
}

void callDisplay(std::list<std::unique_ptr<SmartPointers>> &data){ 
        for(const auto &obj: data){
            obj->display();
    }    
}

int main(){
    // std::list<std::unique_ptr<SmartPointers>> data;

    // data.emplace_back(std::make_unique<SmartPointers>(10));
    // data.emplace_back(std::make_unique<SmartPointers>(20));
    // data.emplace_back(std::make_unique<SmartPointers>(30));
    // data.emplace_back(std::make_unique<SmartPointers>(40));
    // data.emplace_back(std::make_unique<SmartPointers>(50));

    // // data.emplace_back(new SmartPointers(10));
    // // data.emplace_back(new SmartPointers(20));
    // for(const auto &it: data){
    //     //it->display();
    //     callDisplay(it);
    // }

    auto ans = createList();
    addToList(ans);

    callDisplay(ans);
}
//unique ptr does not support copy constructor
//if you want to allocate memory for something that should never be copied then use unique ptr
//no mirror(copy) as both are pointing to the same data...and deleting one of the connection leads to 
// creation of dangling pointer