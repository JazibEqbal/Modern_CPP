#ifndef DOCTOR_H
#define DOCTOR_H
#include "DoctorSpeciality.h"
#include<iostream>

class Doctor
{
private:
    std::string doctorID;
    std::string doctorName;
    enum class DoctorSpeciality doctorSpeciality;
    //friend std::ostream & operator<<(std::ostream &os, Doctor &doc);
public:
    Doctor() =delete;
    Doctor(const Doctor &d) = default;
    Doctor(std::string id, std::string name);
    Doctor(std::string id, std::string name, enum class DoctorSpeciality speciality);
    ~Doctor();

    std::string getDoctorID() const { return doctorID; }
    void setDoctorID(const std::string &doctorID_) { doctorID = doctorID_; }

    std::string getDoctorName() const { return doctorName; }
    void setDoctorName(const std::string &doctorName_) { doctorName = doctorName_; }

    std::string getDoctorSpeciality(){
        if(doctorSpeciality == DoctorSpeciality::MBBS){
            return "MMBS";
        }
        else if(doctorSpeciality == DoctorSpeciality::RADIOLOGIST){
            return "RADIOLOGIST";
        }else {
            return "SURGEON";
        }
    }

    void setDoctorSpeciality(enum DoctorSpeciality speciality){
        if(speciality == DoctorSpeciality::MBBS){
            this->doctorSpeciality = DoctorSpeciality::MBBS;
        }
        else if(speciality == DoctorSpeciality::RADIOLOGIST){
            this->doctorSpeciality = DoctorSpeciality::RADIOLOGIST;
        }
        else {
            this->doctorSpeciality = DoctorSpeciality::SURGEON;
        }
    }

};

#endif // DOCTOR_H
