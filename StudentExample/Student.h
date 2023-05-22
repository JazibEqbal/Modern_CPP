#ifndef STUDENT_H
#define STUDENT_H
#include"StudentBranch.h"
#include<iostream>

class Student
{
private:
    enum class Branch studentBranch;
    std::string studentErpNumber;
    int studentPracticalMarks;
    int studentTheorymarks;
public:
    Student() = delete;
    Student(Student &obj) = delete;
    Student(enum class Branch branch, std::string erpNumber, int practicalMarks, int theoryMarks);
    ~Student();

    std::string getStudentErpNumber() const { return studentErpNumber; }
    void setStudentErpNumber(const std::string &studentErpNumber_) { studentErpNumber = studentErpNumber_; }

    int getStudentPracticalMarks() const { return studentPracticalMarks; }
    void setStudentPracticalMarks(int studentPracticalMarks_) { studentPracticalMarks = studentPracticalMarks_; }

    int getStudentTheorymarks() const { return studentTheorymarks; }
    void setStudentTheorymarks(int studentTheorymarks_) { studentTheorymarks = studentTheorymarks_; }
    
    std::string getStudentBranch(){
        if(studentBranch == Branch::SCIENCE){
            return "SCIENCE";
        }else if(studentBranch == Branch::COMMERCE){
            return "COMMERCE";
        }else{
            return "ARTS";
        }
    }

    std::string setStudentBranch(enum Branch branch){
        if(studentBranch == Branch::SCIENCE){
            this->studentBranch = Branch::SCIENCE;
        }
        else if(studentBranch == Branch::COMMERCE){
            this->studentBranch = Branch::COMMERCE;
        }
        else {
            this->studentBranch = Branch::ARTS;
        }
    }
    friend std::ostream &operator<<(std::ostream &os, Student &s);
};

#endif // STUDENT_H
