#include "OnlineExam.h"

OnlineExam::OnlineExam(EXAM_TYPE type, std::string code, short duration, EXAM_PLATFORM platform)
    : Exam(type,code,duration), examPlatform{platform} {}

OnlineExam::~OnlineExam()
{
    std::cout<<"Online Exam destructor\n";
}
