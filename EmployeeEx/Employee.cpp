#include "Employee.h"

Employee::Employee(int id, std::string name) : employeeId{id}, employeeName{name} {}

Employee::~Employee(){
    std::cout<<"Employee with "
    <<this->employeeId
    <<" destroyed\n";
}

std::ostream &operator<<(std::ostream &os, const Employee &rhs) {
    os << "employeeId: " << rhs.employeeId
       << " employeeName: " << rhs.employeeName;
    return os;
}
