#ifndef EXAM_H
#define EXAM_H
#include "ExamType.h"
#include<iostream>
class Exam
{
private:
    enum class EXAM_TYPE examType;
    std::string examCode;
    short timeDuration;
public:
    Exam() = delete;
    Exam(const Exam &obj) = default;
    Exam(enum class EXAM_TYPE type,std::string code,short duration);
    ~Exam();
    virtual void DisplayAttributes() = 0;
};

#endif // EXAM_H
