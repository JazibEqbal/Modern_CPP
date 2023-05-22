#include "Doctor.h"

enum class DoctorSpeciality speciality()
{
    std::cout << "Choose 1 for MBBS\n"
              << "Choose 2 for RADIOLOGIST\n"
              << "Choose 3 for SURGEON\n";
    int choice;
    std::cin >> choice;
    switch (choice)
    {
    case 1:
        return DoctorSpeciality::MBBS;
        break;
    case 2:
        return DoctorSpeciality::RADIOLOGIST;
        break;
    case 3:
        return DoctorSpeciality::SURGEON;
        break;
    default:
        return DoctorSpeciality::MBBS;
        break;
    }
};

int main(){
    // Doctor *d = new Doctor[3];
    // for(int i=0;i<3;i++){
    //     std::cout<<"Enter Doctor ID\n";
    //     std::string id;
    //     //std::getline(std::cin,id);
    //     std::cin>>id;
    //     std::cin.ignore();
    //     std::cout<<"Enter Doctor Name\n";
    //     std::string name;
    //     //std::cin.ignore();
    //     std::getline(std::cin,name);
    //     enum DoctorSpeciality ans = speciality();
    //     d[i].setDoctorID(id);
    //     d[i].setDoctorName(name);
    //     d[i].setDoctorSpeciality(ans);
    // };
    
    // for(int i=0;i<3;i++){
    //     std::cout<<"Doctor ID is: "<<d[i].getDoctorID()<<"\n";
    //     std::cout<<"Doctor Name is: "<<d[i].getDoctorName()<<"\n";
    //     std::cout<<"Doctor Speciality is: "<<d[i].getDoctorSpeciality()<<"\n\n";
    // }
    
    Doctor *d1 = new Doctor("11","jaj",DoctorSpeciality::MBBS);
    Doctor *d2 = new Doctor("111","hj",DoctorSpeciality::RADIOLOGIST);
    Doctor *d3 = new Doctor("1111","djddjaj",DoctorSpeciality::SURGEON);

    Doctor *arr[3] = {d1,d2,d3};
    //delete []d;
    return 0;
}