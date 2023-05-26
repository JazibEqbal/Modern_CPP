#include<iostream>

/*
  print this
  This is line 1
  This is a "demo" (for) line 2
  Thanks "\n""\t" for waiting
  Goodbye
*/

int main(){
    std::string data_raw = R"#(This is line 1   //"# is the delimeter here 
This is "demo" for line 2
This is line (3)"
Thanks "\n""\t" (for) waiting
Goodbye)#";
    std::cout<<data_raw<<"\n";
    return 0;
}

//delimeter indicates limits