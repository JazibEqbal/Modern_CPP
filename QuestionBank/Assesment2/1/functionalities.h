#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H
#include "User.h"
#include<iostream>
#include<functional>
#include<algorithm>
#include<list>

extern std::function<float(std::list<User*> &obj) > avergaeUserIncome;

extern std::function<std::list<std::string>(std::list<User*>,int)> userAge;

extern std::function<User*(std::list<User*> &obj) > mimimumUserAge;

extern std::function<void(std::list<User*> &obj) > printDetails;

#endif // FUNCTIONALITIES_H
