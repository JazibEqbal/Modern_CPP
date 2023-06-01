#include "functionalities.h"

enum class EXAM_TYPE getExam(){
    std::cout<<"Choose 1 for UNIT_TEST\n"
             <<"Choose 2 for MID_TERM\n"
             <<"Choose 3 for END_TERM\n";
    int options;
    std::cin>>options;
    switch (options)
    {
    case 1:
        return EXAM_TYPE::UNIT_TEST;
        break;
    case 2:
        return EXAM_TYPE::MID_TERM;
        break;
    case 3:
        return EXAM_TYPE::END_SEM;
        break;
    default:
        return EXAM_TYPE::END_SEM;
        break;
    }
}

enum class EXAM_PLATFORM getPlatform(){
    std::cout<<"Choose 1 for UNIT_TEST\n"
             <<"Choose 2 for MID_TERM\n"
             <<"Choose 3 for END_TERM\n";
    int options;
    std::cin>>options;
    switch (options)
    {
    case 1:
        return EXAM_PLATFORM::UNIT_TEST;
        break;
    case 2:
        return EXAM_PLATFORM::MID_TERM;
        break;
    case 3:
        return EXAM_PLATFORM::END_SEM;
        break;
    default:
        return EXAM_PLATFORM::END_SEM;
        break;
    }
}

void menu(){
    std::cout<<"Enter number of objects to be created: ";
    int n;
    std::cin>>n;
    OnlineExam *exam[n];
    for(int i=0;i<n;i++){
        enum EXAM_TYPE ans = getExam();
        std::cout<<"Enter Exam Code: ";
        std::string code;
        std::cin.ignore();
        std::getline(std::cin,code);
        std::cout<<"Enter exam duration: ";
        short duration;
        std::cin>>duration;
        enum EXAM_PLATFORM anms;
    };
}
