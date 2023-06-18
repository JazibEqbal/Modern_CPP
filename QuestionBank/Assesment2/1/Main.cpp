#include "User.h"
#include "functionalities.h"


int main(){
    User *u1 = new User("1",23,45000.50f);
    User *u2 = new User("1",93,139700.50f);
    User *u3 = new User("1",23,45000.50f);

    std::list<User*> list = {u1,u2,u3};

    //std::cout<<avergaeUserIncome(list)<<"\n";
    //std::cout<<mimimumUserAge(list)<<"\n";
    //printDetails(list);
    auto res = userAge(list,23);
    for(auto &it:res){
        std::cout<<it<<"\n";
    }
}