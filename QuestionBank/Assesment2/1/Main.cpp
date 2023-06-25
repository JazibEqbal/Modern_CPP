#include "User.h"
#include "functionalities.h"


int main(){
    User *u1 = new User("1",23,45000.50f);
    User *u2 = new User("1",23,45000.50f);
    User *u3 = new User("1",23,45000.50f);

    std::list<User*> list = {u1,u2,u3};

    std::cout<<avergaeUserIncome(list);
    std::cout<<mimimumUserAge(list);
    printDetails(list);
}