#include "Student.h"

Student *arr[2];

enum class Branch getBranch(){
    std::cout<<"Choose 1 for SCIENCE\n"
             <<"Choose 2 for COMMERCE\n"
             <<"Choose 3 for ARTS\n";
    int choice;
    std::cin>>choice;
    switch (choice)
    {
    case 1:
        return Branch::SCIENCE;
        break;
    case 2:
        return Branch::COMMERCE;
        break;
    case 3:
        return Branch::ARTS;
        break;
    default:
        return Branch::SCIENCE;
        break;
    }            
}

int FindTotalMarks(Student& obj){
    return obj.getStudentPracticalMarks() + obj.getStudentTheorymarks();
};

bool CheckStudent(std::string str){
     for(int i=0;i<2;i++){
        return (arr[i]->getStudentErpNumber() == str);
    }
}

int main(){
    // Student *s1 = new Student(Branch::SCIENCE, "1x",45,34);
    // Student *s2 = new Student(Branch::SCIENCE, "2x",50,31);
    // Student *s3 = new Student(Branch::SCIENCE, "3x",45,10);
    // Student *s4 = new Student(Branch::SCIENCE, "4x",15,20);
    // Student *s5 = new Student(Branch::SCIENCE, "5x",55,40);

    // arr[0] = {s1};
    // arr[1] = {s2};
    // arr[2] = {s3};
    // arr[3] = {s4};
    // arr[4] = {s5};
    
    for(int i=0;i<2;i++){
        enum Branch ans = getBranch();
        std::string id;
        std::cin>>id;
        int pracMarks;
        std::cin>>pracMarks;
        int theoryMarks;
        std::cin>>theoryMarks;
        arr[i]=new Student(ans,id,pracMarks,theoryMarks);
    }

    std::cout<<"The Total marks of student with ERP Number : "<<arr[1]->getStudentErpNumber()<<" is "<<FindTotalMarks(*arr[1])<<"\n";
    std::cout<<"Enter Erp Number of student\n";
    std::string erpNumber;
    std::cin.ignore();
    std::getline(std::cin,erpNumber);
    std::cout<<CheckStudent(erpNumber)<<"\n";

    std::cout<<*arr[1];

    for(int i=0;i<2;i++){
        delete arr[i];
    }
}