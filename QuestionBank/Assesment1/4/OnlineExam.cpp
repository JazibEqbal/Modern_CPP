#include "OnlineExam.h"

OnlineExam::OnlineExam(EXAM_TYPE type, std::string code, short duration, EXAM_PLATFORM platform)
    : Exam(type,code,duration), examPlatform{platform} {}

OnlineExam::~OnlineExam()
{
    std::cout<<"Online Exam destructor\n";
}

std::string displayExamPlatform(enum class EXAM_PLATFORM platform){
    if(platform == EXAM_PLATFORM::TEAMS){
        return "TEAMS";
    } else if(platform == EXAM_PLATFORM::MEET){
        return "MEET";
    } else{
        return "ZOOM";
    }   
}

void OnlineExam::DisplayAttributes()
{
    std::cout<<"Exam Type:"<<displayExamType(getExamType())<<"\n";
    std::cout<<"Exam Code: "<<getExamCode()<<"\n";
    std::cout<<"Time duration: "<<getTimeDuration()<<"\n";
    std::cout<<"Exam Platform: "<<displayExamPlatform(getExamPlatform())<<"\n\n";
}
