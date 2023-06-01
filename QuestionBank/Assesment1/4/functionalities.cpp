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
    std::cout<<"Choose 1 for MEET\n"
             <<"Choose 2 for TEAMS\n"
             <<"Choose 3 for ZOOM\n";
    int options;
    std::cin>>options;
    switch (options)
    {
    case 1:
        return EXAM_PLATFORM::MEET;
        break;
    case 2:
        return EXAM_PLATFORM::TEAMS;
        break;
    case 3:
        return EXAM_PLATFORM::ZOOM;
        break;
    default:
        return EXAM_PLATFORM::MEET;
        break;
    }
}

enum class EXAM_TOPIC getTopic(){
    std::cout<<"Choose 1 for ALGORITHMS\n"
             <<"Choose 2 for DS\n"
             <<"Choose 3 for C\n";
    int options;
    std::cin>>options;
    switch (options)
    {
    case 1:
        return EXAM_TOPIC::ALGORITHMS;
        break;
    case 2:
        return EXAM_TOPIC::DS;
        break;
    case 3:
        return EXAM_TOPIC::C;
        break;
    default:
        return EXAM_TOPIC::C;
        break;
    }
}

void menu(){
    std::cout<<"Take Online Exam? Press 1\n";
    std::cout<<"Take Offline Exam? Press 2\n";
    int options;
    std::cin>>options;
    switch(options){
        case 1:{
            std::cout<<"Enter number of objects to be created: ";
            int n;
            std::cin>>n;
            OnlineExam *onlineExam[n];
            for(int i=0;i<n;i++){
                std::cout<<"Enter exam details for "<<i+1<<" exam.\n";
                enum EXAM_TYPE ans = getExam();
                std::cout<<"Enter Exam Code: ";
                std::string code;
                std::cin.ignore();
                std::getline(std::cin,code);
                std::cout<<"Enter exam duration: ";
                short duration;
                std::cin>>duration;
                enum EXAM_PLATFORM res = getPlatform();
                onlineExam[i] = new OnlineExam(ans,code,duration,res);
            };
            std::cout<<"All offline exams created are:\n";
                for(auto *it: onlineExam){
                    it->DisplayAttributes();
        }
        break;
      }
        case 2:{
            std::cout<<"Enter number of objects to be created: ";
            int n;
            std::cin>>n;
            OfflineExam *offlineExam[n];
            for(int i=0;i<n;i++){
                std::cout<<"Enter exam details for "<<i+1<<" exam.\n";
                enum EXAM_TYPE ans = getExam();
                std::cout<<"Enter Exam Code: ";
                std::string code;
                std::cin.ignore();
                std::getline(std::cin,code);
                std::cout<<"Enter exam duration: ";
                short duration;
                std::cin>>duration;
                std::cout<<"Enter exam location: ";
                std::string location;
                std::cin.ignore();
                std::getline(std::cin,location);
                enum EXAM_TOPIC res = getTopic();
                offlineExam[i] = new OfflineExam(ans,code,duration,location,res);            
        }
        std::cout<<"All offline exams created are:\n";
                for(auto *it: offlineExam){
                    it->DisplayAttributes();
        }
        break;
    }
        default:
            exit(0);
    }
}