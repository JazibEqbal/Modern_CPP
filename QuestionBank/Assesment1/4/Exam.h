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
    virtual ~Exam();
    virtual void DisplayAttributes() = 0;

    std::string getExamCode() const { return examCode; }
    void setExamCode(const std::string &examCode_) { examCode = examCode_; }

    short getTimeDuration() const { return timeDuration; }
    void setTimeDuration(short timeDuration_) { timeDuration = timeDuration_; }

    enum class EXAM_TYPE getExamType() const { return examType;};
};
std::string displayExamType(enum class EXAM_TYPE examType);

#endif // EXAM_H
