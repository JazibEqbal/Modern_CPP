#ifndef ONLINEEXAM_H
#define ONLINEEXAM_H
#include "ExamPlatform.h"
#include "Exam.h"

class OnlineExam : public Exam
{
private:
    enum class EXAM_PLATFORM examPlatform;
public:
    OnlineExam(const OnlineExam &obj) = default;
    OnlineExam(enum class EXAM_TYPE type,std::string code,short duration,enum class EXAM_PLATFORM platform);
    ~OnlineExam();

    void AverageMarks(int *arr[5]);
    void DisplayAttributes() override;

    enum class EXAM_PLATFORM getExamPlatform() const { return  examPlatform;};

};
std::string displayExamPlatform(enum class EXAM_PLATFORM platform);

#endif // ONLINEEXAM_H
