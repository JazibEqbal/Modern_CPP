#include "functionalities.h"

void operation(std::list<Account *> &acc, std::list<std::function<float(std::list<Account*> &v)>> fun)
{
    for(auto &it: fun){
        std::cout<<it(acc)<<"\n";
    }
}
void operation2(std::list<Transaction *> &acc, std::list<std::function<float(std::list<Transaction*> &v)>> fun)
{
    for(auto &it: fun){
        std::cout<<it(acc)<<"\n";
    }
}