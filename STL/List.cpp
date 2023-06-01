#include <list> //doubly linked list
#include <iostream>
#include<optional>
#include<functional>
/*
    conatiners need to be initializied
*/
std::optional<std::list<int>> CreateList()
{
    std::string msg = R"(Enter 1 for default,2 for creating a initialized list,3 for copy)";
    int choice;
    std::cin >> choice;
    switch (choice)
    {
    case 1:
    {
        return std::list<int>{};
        break;
    }
    case 2:
    {
        int size = 0;
        std::cout << "Enter size\n";
        std::cin >> size;
        std::list<int> data(size);
        int element = 0;
        for (int i = 0; i < size; i++)
        {
            std::cin >> element;
            data.push_back(element);
        };
        // data.emplace_back(6); use this when working with classes
        return data;
        break;
    }
    case 3:
    {
        std::list<int> data = {1, 2, 3, 4};
        std::list<int> values(data); // copy everything from data into the values

        std::list<int> items;
        for (auto itr = data.rbegin(); itr != data.rend(); itr++)
        {
            items.push_back(*itr); // reverse
        }
        return items;
    }
    default:
        return {};
        break;
    }
}

int main(){
    auto result = CreateList();
    if(result.has_value()){
        std::cout<<result.value().size()<<"\n";
    }else{
        std::cout<<"List was not created\n";
    }
}