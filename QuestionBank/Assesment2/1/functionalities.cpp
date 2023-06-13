#include "functionalities.h"

std::function<float(std::list<User *> &obj)> avergaeUserIncome = [](std::list<User *> &obj)
{
    if (obj.empty())
    {
        throw std::runtime_error("List passed is empty"); // throwing errorm if list is empty
    }
    float sum = 0;
    for (auto *it : obj)
    {
        sum += it->getUserIncome();
    }
    return (sum / obj.size()); // returning avg by dividing by total sise of list
};

// function to return all userId whose age matches passed argument
std::function<std::list<std::string>(std::list<User *>, int)> userAge = [](std::list<User *> obj, int age)
{
    // Checking exceptions
    if (obj.empty())
    {
        throw std::runtime_error("List is empty operation cannot be performed"); // throwing error if list passed is empty
    }
    if (age < 0)
    {
        throw std::runtime_error("No value passed\n");
    }
    std::list<std::string> list;
    for (auto *it : obj)
    {
        if (it->getUserAge() == age)
        {
            list.push_back(it->getUserId());
        }
    }
    return list;
};
// function to calculate minimum age
std::function<User(std::list<User *>)> mimimumUserAge = [](std::list<User *> obj)
{
    int min = INT16_MAX;
    User *user;
    if (obj.empty())
    {
        throw std::runtime_error("List passed is empty"); // throwing error if list passed is empty
    }
    for (auto *it : obj)
    {
        if (min > it->getUserAge())
        {
            min = it->getUserAge();
            user = it;
        }
    }
    return *user;
};

// function to print details of users
std::function<void(std::list<User *> &obj)>
    printDetails = [](std::list<User *> &obj)
{
    if (obj.empty())
    {
        throw std::runtime_error("List passed is empty"); // throwing errorm if list is empty
    }
    for (auto *it : obj)
    {
        if (it->getUserAge() > 30 && it->getUserIncome() >= 40000 && it->getUserIncome() == 1000 * (1.5 * it->getUserAge()))
        {
            std::cout << *it << "\n";
        }
    }
};
