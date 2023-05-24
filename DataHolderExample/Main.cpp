#include "DataHolder.h"
#include<list>

int main(){
    std::list<int> li = {1,2,3,4,5};
    DataHolder<int> *d1 = new DataHolder<int>(li);
    delete d1;
}