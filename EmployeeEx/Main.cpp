#include "Employee.h"

int main(){
    Employee *e2= new Employee(101,"jaja");  //e2 is a pointer of  Employee Type
    Employee *e3 =new Employee(*e2);
    return 0;
}



/*
#include<unordered_map>
#include<list>

data is standard unordered map of string keys and standard list of integers values

std::unordered_map<std::string, std::list<int>> data; 
*/


