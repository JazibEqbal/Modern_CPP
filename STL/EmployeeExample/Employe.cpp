#include "Employe.h"

Employe::Employe(std::string id, float salary, DEPARTMENT dept) : employeeID{id}, employeeSalary{salary}, department{dept} {}

Employe::~Employe()
{
    std::cout << "Employee destroyed\n";
}

std::ostream &operator<<(std::ostream &os, const Employe &rhs)
{
    os << "employeeID: " << rhs.employeeID
       << " employeeSalary: " << rhs.employeeSalary
       << " department: " << displayDepartment(rhs.department);
    return os;
}

float Employe::operator+(const Employe &obj)
{
    employeeSalary = employeeSalary + obj.employeeSalary;
    return employeeSalary;
}

std::string displayDepartment(enum class DEPARTMENT dept)
{
    if (dept == DEPARTMENT::ADMIN)
    {
        return "ADMIN";
    }
    else if (dept == DEPARTMENT::HR)
    {
        return "HR";
    }
    else if (dept == DEPARTMENT::SALES)
    {
        return "SALES";
    }
    else
    {
        return "IT";
    }
}