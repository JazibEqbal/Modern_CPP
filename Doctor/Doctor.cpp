#include "Doctor.h"

Doctor::Doctor(std::string id, std::string name) : doctorID{id}, doctorName{name} {}

Doctor::Doctor(std::string id, std::string name, DoctorSpeciality speciality) : doctorID{id}, doctorName{name}, doctorSpeciality{speciality}{}

Doctor::~Doctor(){
    std::cout<<"Doctor with "
    <<this->doctorID
    <<" is destroyed\n";
}

/*
   std::ostream & operator<<(std::ostream & os, const Doctor &doc){
    os <<"Doctor id: "<<doc.doctorID
    <<"Doctor Name: " <<doc.doctorName
    <<"Doctor Speciality: "<<doc.getDoctorSpeciality();
    return os;
   }
*/