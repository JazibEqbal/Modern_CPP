#ifndef AUTOMOBILE_H
#define AUTOMOBILE_H
#include<list>
#include<iostream>
#include<functional>

class AutoMobile
{
private:
    std::string autoMobileNumber;
    std::reference_wrapper<std::list<float>> autoMobileReadings;
public:
    AutoMobile(std::string autoNumber, decltype(autoMobileReadings) readings);
    ~AutoMobile();

    std::string getAutoMobileNumber() const { return autoMobileNumber; }
    void setAutoMobileNumber(const std::string &autoMobileNumber_) { autoMobileNumber = autoMobileNumber_; }

    std::reference_wrapper<std::list<float>> getAutoMobileReadings() const { return autoMobileReadings; }
    void setAutoMobileReadings(const std::reference_wrapper<std::list<float>> &autoMobileReadings_) { autoMobileReadings = autoMobileReadings_; }

    friend std::ostream &operator<<(std::ostream &os, const AutoMobile &rhs);


  
};

#endif // AUTOMOBILE_H
