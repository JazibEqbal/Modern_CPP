#include "OfflineExam.h"

OfflineExam::OfflineExam(EXAM_TYPE type, std::string code, short duration, std::string location, EXAM_TOPIC topic)
    : Exam(type,code,duration) ,examLocation{location}, examTopic{topic} {}

OfflineExam::~OfflineExam()
{
    std::cout<<"Offline exam\n";
}

std::string displayExamTopic(enum class EXAM_TOPIC topic){
    if(topic == EXAM_TOPIC::ALGORITHMS){
        return "ALGORITHMS";
    } else if(topic == EXAM_TOPIC::DS){
        return "DS";
    } else{
        return "C";
    }
}

void OfflineExam::changeLocation(std::string newLocation)
{
    setExamLocation(newLocation);
}

void OfflineExam::DisplayAttributes()
{
    std::cout<<"Exam Type:"<<displayExamType(getExamType())<<"\n";
    std::cout<<"Exam Code: "<<getExamCode()<<"\n";
    std::cout<<"Time duration: "<<getTimeDuration()<<"\n";
    std::cout<<"Exam Platform: "<<displayExamTopic(getExamTopic())<<"\n\n";
}