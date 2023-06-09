#include<iostream>
#include<functional>

using namespace std::placeholders;

int product(int x,int y=100){
    return x*y;
}
//bind way
int formula(int x,int y,int z,int a){
    return ((x-y)*2/a);
}
//USE CASE with lambda
auto fn1 = [](int num){return num * num;};
auto fn2 = [](int num,int factor){return num * factor;};

int main(){
    auto f1 = product(20);
    auto f2 = std::bind(&formula,_1,_2,10,100);  // z and are fixed

//USE CASE
    //don't use & with lambda when passing 
    auto fn3 = std::bind(fn2,_1,4); //factor fixed to 4
    fn3(10);
    //creating a function wrapper
    std::vector<std::function<int(int)>>v1 = {fn1,fn3};

    std::cout<<f1<<"\n";
    //in class
    bindDemo obj;
    auto ans = std::bind(&bindDemo::magic,&obj,100,2);

}
//remap
int fun(int x,int y,int z){
    return (x+y) -z;
}

//using std::bind remap
auto ans  = std::bind(&fun,_3,_2,_1);  //passing 3 arument as 1st argument to user and vice versa

/*you can bind an existing functions's parameter to a value so that it can be
  stored in a container of which expected types does not match with a function to be stored.(ref,fn1&fn3);

  you can remap the order of arguments of an existing function
*/

class bindDemo
{
private:
    /* data */
public:
    bindDemo()=default;
    int magic(int x,int y){
        return x*y;
    }
    ~bindDemo(){};
};