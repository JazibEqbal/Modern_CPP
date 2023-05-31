#include "AutoMobile.h"

AutoMobile::AutoMobile(std::string autoNumber, std::reference_wrapper<std::list<float>> readings)
    : autoMobileNumber{autoNumber} , autoMobileReadings{readings} {}

AutoMobile::~AutoMobile()
{
    std::cout<<"Auto Des\n";
}

std::ostream &operator<<(std::ostream &os, const AutoMobile &rhs) {
    os << "autoMobileNumber: " << rhs.autoMobileNumber
       << " autoMobileReadings: " ;
        for(auto &it: rhs.autoMobileReadings.get()){
            os <<it<<" ";
        }
    return os;
}
