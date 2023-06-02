#include "function.h"

float FindHighestInsurance(std::list<MyCar *> &obj) {
    float max =0;
    std::find_if(obj.begin(),obj.end(),[&](const MyCar *car){
        return car->getCarPrice() > max;
    });
}
