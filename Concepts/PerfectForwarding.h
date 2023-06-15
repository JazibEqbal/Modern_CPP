#ifndef PERFECTFORWARDING_H
#define PERFECTFORWARDING_H

#include<iostream>

class PerfectForwarding
{
private:
    int empId;
    float empSalary;
public:
    PerfectForwarding(int id,float salary) : empId{id}, empSalary{salary} {}
    ~PerfectForwarding() {
        std::cout<<"Destroyed\n";
    }
    //if the object is const which is declared in findTax parameter then you must write "const" keyword after function declaration to access this method
    float calculateSalary() const {
        return .1f* this->empSalary;
    }

    int getEmpId() const { return empId; }
    void setEmpId(int empId_) { empId = empId_; }

    float getEmpSalary() const { return empSalary; }
    void setEmpSalary(float empSalary_) { empSalary = empSalary_; }

    friend std::ostream &operator<<(std::ostream &os, const PerfectForwarding &rhs) {
        os << "empId: " << rhs.empId
           << " empSalary: " << rhs.empSalary;
        return os;
    }
};

#endif // PERFECTFORWARDING_H
