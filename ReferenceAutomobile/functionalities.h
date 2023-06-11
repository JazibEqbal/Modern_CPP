#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H
#include "AutoMobile.h"

void operation(std::list<float> &data,std::function<std::list<float>(std::list<float>)> fun);

extern std::list<float> autoMobileReading(std::list<float> read);

// std::list<float> autoMobileReading(std::list<float> read);

// //operation Fn that accepts a autoMobileReadings & a operation to be performed
// void operation(std::list<float>& read, std::function<std::list<float>(std::list<float>)> f1);

#endif // FUNCTIONALITIES_H
