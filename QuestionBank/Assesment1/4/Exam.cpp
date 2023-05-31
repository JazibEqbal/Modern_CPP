#include "Exam.h"

Exam::Exam(EXAM_TYPE type, std::string code, short duration) : examType{type} ,examCode{code}, timeDuration{duration} {}

Exam::~Exam()
{
    std::cout<<"Exam destructor\n";
}
std::string displayExamType(enum class EXAM_TYPE examType){
    if(examType == EXAM_TYPE::UNIT_TEST){
        return "UNIT_TEST";
    } else if(examType == EXAM_TYPE::MID_TERM){
        return "MID_TERM";
    } else{
        return "END_SEM";
    }
}