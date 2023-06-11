#include "AutoMobile.h"
#include <functional>
#include "functionalities.h"

void operation(std::list<float> &data,std::function<std::list<float>(std::list<float>)> f1){
    
    std::cout<<"\n\nThe Readings above 4.5 are : ";
    auto re = f1(data);

    if(re.size()){
        for(auto it : re)
            std::cout<<it<<"\t";
    }
}

std::list<float> autoMobileReading(std::list<float> read){
    std::list<float> res(read.size());
    auto itr = std::copy_if(read.begin(),
        read.end(),
        res.begin(),
        [](float number){return number > 4.5;}
    );

    res.resize(std::distance(res.begin(),itr));
    return res;
}
