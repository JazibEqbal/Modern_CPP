#include "User.h"

User::User(std::string id, int age, float income) : userId{id}, userAge{age}, userIncome{income} {}

User::~User()
{
    std::cout<<"User destroyed\n";
}

float User::operator+(const User &obj)
{
    userIncome = userIncome + obj.userIncome;
    return userIncome;
}

std::ostream &operator<<(std::ostream &os, const User &rhs) {
    os << "userId: " << rhs.userId
       << " userAge: " << rhs.userAge
       << " userIncome: " << rhs.userIncome;
    return os;
}
