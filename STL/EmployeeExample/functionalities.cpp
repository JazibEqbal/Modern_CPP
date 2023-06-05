#include "functionalities.h"
#include <algorithm>

std::optional<std::list<Employe *>> FindEmployeeAboveThreshold(std::list<Employe *> &obj, float threshold)
{
    std::list<Employe *> list(obj.size());
    if (obj.size() <= 0)
    {
        throw std::runtime_error("List is empty");
    }
    if (threshold < 0)
    {
        throw std::runtime_error("Threshold can't be a negative value!");
    }
    auto itr = std::copy_if(obj.begin(), obj.end(), list.begin(), [&](Employe *obj)
                 { return obj->getEmployeeSalary() > threshold; }); //std::copy_if returns an iterator poinitng to the last element which it has inserted
    list.resize(std::distance(list.begin(),itr));
    // for(auto *it : obj){
    //     if(it->getEmployeeSalary() > threshold){
    //         list.push_back(it);
    //     }
    // }
    if (list.size() == 0)
    {
        return {};
    }
    else
    {
        return list;
    }
};

std::optional<const Employe*> FindEmployeeWithGivenId(std::list<Employe *> &obj, std::string id)
{
    if (obj.size() <= 0)
    {
        throw std::runtime_error("List is empty");
    }

    auto res = std::find_if(obj.begin(), obj.end(),
                            [&](const Employe *e)
                            { return e->getEmployeeID() == id; });

    if (res == obj.end())
    {
        return {};
    }

    else{
        return *res;
    }
};

float FindCombinedSalary(std::list<Employe *> &obj)
{
    float total = 0.0f;
    for (auto *it : obj)
    {
        total += it->getEmployeeSalary();
    }
    return total;
};
