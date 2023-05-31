#include "Exam.h"

Exam::Exam(EXAM_TYPE type, std::string code, short duration) : examType{type} ,examCode{code}, timeDuration{duration} {}

Exam::~Exam()
{
    std::cout<<"Exam destructor\n";
}
