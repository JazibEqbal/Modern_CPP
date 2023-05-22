#include "Student.h"

Student::Student(Branch branch, std::string erpNumber, int practicalMarks, int theoryMarks)
: studentBranch{branch} , studentErpNumber{erpNumber} , studentPracticalMarks{practicalMarks}, studentTheorymarks{theoryMarks}{}

Student::~Student()
{
    std::cout<<"Student with ERP Number: "
    <<this->studentErpNumber
    <<" is destroyed\n";
}

std::ostream &operator<<(std::ostream &os, Student &s)
{
    os<<"Student Branch is: "<<s.getStudentBranch()<<"\n"
      <<"Student Erp Number is: "<<s.getStudentErpNumber()<<"\n"
      <<"Student Practical Marks is: "<<s.getStudentPracticalMarks()<<"\n"
      <<"Student Theory Marks is: "<<s.getStudentTheorymarks()<<"\n";
}
