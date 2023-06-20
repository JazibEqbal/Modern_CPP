#include<iostream>
#include<thread>
#include<future>

/*
    async creates a thread for separate execution or executes code asynchronously.
*/

int ans=0;

int fact(std::future<int> &fut){ //this thread goes in block state untill input is provided
    int n=fut.get();
    std::cout<<"Factorial Started\n";
    std::this_thread::sleep_for(std::chrono::seconds(2));
    if(n < 0){
        throw std::runtime_error("Negative number exception!");
    }
    if(n ==0 || n ==1){
        ans= 1;
    }
    int f=1;
    for(int i=2;i<= n;i++){
        f *=i;
    }
    return ans=f;
}

int s=0;
void square(int n){
    std::cout<<"Square Started\n";
    s = n*n;
}
//lambda 
auto s = [](std::future<int> &ft){int n = ft.get();return n*n;};

int main(){
    //promise future communication
    std::promise<int> pr;                       //creating a promise  //for setting
    std::future<int> input = pr.get_future();   //input will be provided in future //future for getting
    //start factorial in a different thread where input will be provided in future
    std::future<int> r1 = std::async(std::launch::async,&fact,std::ref(input));
    //std::future<void> r2 = std::async(std::launch::async,&square,5);
    std::thread t(square,5);
    int n;
    std::cin>>n;
    pr.set_value(n);    //fullfilling promise

    //r1 and r2 are equivalent to join. waut till value is fetched
    //r2.get();
    t.join();
    std::cout<<"Square "<<s<<"\n";
    r1.get();
    std::cout<<"Fact "<<ans<<"\n";
    
}