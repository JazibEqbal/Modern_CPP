#include<iostream>
#include<cstdarg>
//varargs : variable number of arguments
void sum(int count, ...){ // count is the first argument of fun call, ... is rest
    //create a list where we can save information about this varargs
    va_list args;
    //fetch the starting vale of varargs
    va_start(args,count);
    //keep fetching the next value from varargs till all values are exhausted
    int total = 0;
    int fetched_value;
    for(int i=0;i<count;i++){
        fetched_value = va_arg(args,int);  //int is the typeof data we are expecting
        std::cout<<fetched_value<<"\n";
        total += fetched_value;
    }
    //close the varargs list

}

int main(){
    sum(1);
    sum(1,2,3,4);
    sum(10,20,30);
}