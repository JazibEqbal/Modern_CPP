#ifndef EMPLOYE_H
#define EMPLOYE_H
#include <iostream>
#include "Department.h"
class Employe
{
private:
    std::string employeeID;
    float employeeSalary;
    enum class DEPARTMENT department;

public:
    Employe() = delete;
    Employe(const Employe &obj) = default;
    Employe(std::string id, float salary, enum class DEPARTMENT dept);
    ~Employe();

    std::string getEmployeeID() const { return employeeID; }
    void setEmployeeID(const std::string &employeeID_) { employeeID = employeeID_; }

    float getEmployeeSalary() const { return employeeSalary; }
    void setEmployeeSalary(float employeeSalary_) { employeeSalary = employeeSalary_; }

    enum class DEPARTMENT getDepartment() const { return department; };

    float operator+(const Employe &obj);

    friend std::ostream &operator<<(std::ostream &os, const Employe &rhs);
};

std::string displayDepartment(enum class DEPARTMENT dept);

#endif // EMPLOYE_H
