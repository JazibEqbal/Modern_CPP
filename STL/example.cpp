#include<list>
#include<iostream>
#include<algorithm>

int main(){
    std::list<int> data = {1,2,3,4,5,6,7,8,9,10};
    std::list<int> results;
    //copy elements from data into results which are divisble by 5
    std::copy_if(data.begin(),data.end(),results.begin(),[](int num) {return num %5 == 0;});
}