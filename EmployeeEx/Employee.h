#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include<iostream>

class Employee
{
private:
    int employeeId;
    std::string employeeName;
public:
    //a constructor to create an employee object without providing id or name
    Employee() = default;   //defaulted default constructor
    //Employee() = delete;   //deleted default constructor ---> to disable
    Employee(const Employee &obj) = default;  // defaulted copy constructor for shallow copy
    Employee(int id,std::string name);  //user defined parameterized constructor
    virtual ~Employee();

    int getEmployeeId() const { return employeeId; }
    void setEmployeeId(int employeeId_) { employeeId = employeeId_; }

    std::string getEmployeeName() const { return employeeName; }
    void setEmployeeName(const std::string &employeeName_) { employeeName = employeeName_; }

    friend std::ostream &operator<<(std::ostream &os, const Employee &rhs);
};

#endif // EMPLOYEE_H
