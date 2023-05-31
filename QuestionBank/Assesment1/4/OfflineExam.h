#ifndef OFFLINEEXAM_H
#define OFFLINEEXAM_H
#include "Exam.h"
#include "ExamTopics.h"
class OfflineExam : public Exam
{
private:
    std::string examLocation;
    enum class EXAM_TOPIC examTopic;
public:
    OfflineExam(const OfflineExam &bj) = default;
    OfflineExam(enum class EXAM_TYPE type,std::string code,short duration,std::string location,enum class EXAM_TOPIC topic);
    ~OfflineExam();

    std::string getExamLocation() const { return examLocation; }
    void setExamLocation(const std::string &examLocation_) { examLocation = examLocation_; }

    void changeLocation(std::string newLocation);
    void DisplayAttributes() override;

    enum class EXAM_TOPIC getExamTopic() const { return examTopic;};
};
std::string displayExamTopic(enum class EXAM_TOPIC topic);

#endif // OFFLINEEXAM_H
