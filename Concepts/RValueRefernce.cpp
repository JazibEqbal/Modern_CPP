#include<iostream>

void square(int&& data){   //square takes one r value reference  //square is expecting a refernce to a rvalue
    std::cout<<"Square of "<<data<<" is: " <<data*data<<"\n"; 
}

int main(){
    
    /*
      10 is a literal value.  It is also called a temporary
      10 is also called an rvalue since it does not have its own address

      10 is not declared as a variable so it is temporary

      r value are temporary and means you can also refernce an rvalue by &&;
      lvalue-- something that has an address (if you want to pass variable then)

      compiler deletes temporary after the function(square()) ends or there is no other function to accept temporary value
      
    */
    square(10);
    return 0;
}

//with rvalue refernces move c-mantics is possible...allows transfer of ownership