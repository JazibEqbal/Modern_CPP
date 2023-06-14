#include<iostream>
#include<thread>
#include<future>

int ans=0;
void fact(std::future<int> &fut){
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
    ans = f;
}

int s=0;
void square(int n){
    std::cout<<"Square Started\n";
    s = n*n;
}

int main(){
    //promise future communication
    std::promise<int> pr;                       //creating a promise
    std::future<int> input = pr.get_future();
    //start factorial in a different thread where input will be provided in future
    std::future<void> r1 = std::async(std::launch::async,&fact,std::ref(input));
    std::future<void> r2 = std::async(std::launch::async,&square,5);

    int n;
    std::cin>>n;
    pr.set_value(n);

    //r1 and r2 are equivalent to join. waut till value is fetched
    r2.get();
    std::cout<<"Square "<<s<<"\n";
    r1.get();
    std::cout<<"Fact "<<ans<<"\n";
    
}