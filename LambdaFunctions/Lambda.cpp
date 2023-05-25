#include<iostream>
#include<list>
//normalfunction
int square(int num){
    return num * num;
}
int cube(int num){
    return num*num*num;
}
//lambda function
auto f = [] (int num) { return num*num;};
auto f2 = [] (int num) {return num*num*num;};
/*
  opeartion fun should accept a list of values & a logic of some operation
  i want to perform on each element of the list

  the operation fun should then loop and one by one by one apply the operation on the values
*/

//basic CPP not modern
void operation(std::list<int> &&data, int (*function)(int)){   //passing pointer(address) to the function
    for(int val : data){
        std::cout<<function(val)<<"\n";
    }
}

int main(){
    //this is creating a pointer to a function refer line 24
    //int (*ptr)(int) = &square;  //ptr is a pointer to a fun that accepts one integer and returns integer
    //int ans = (*ptr)(10);  //calling by dereferencing it
    //std::cout<<ans<<"\n";

    operation(std::list<int> {1,2,3,4}, square);
    operation(std::list<int> {1,2,3,4}, cube);

    //lamda function
    operation(std::list<int> {1,2,3,4}, f);
    operation(std::list<int> {1,2,3,4}, [] (int num){return num*num*num;});

    // operation(std::list<int> {2,4,6} , [] (int num) {for(int data: num){if(data %2 != 0) return true;}})

    auto f = [] (int num) { return num*num;};
   
    return 0;
}

/*
  lambda func allows you to do functional programming
  
*/