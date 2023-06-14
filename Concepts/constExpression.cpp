#include<iostream>

constexpr int square(int n){
    return n*n;
}

int cube(int n){
    return n*n*n;
}

class constExpression
{
private:
    int demoId;
public:
    constexpr constExpression(int id) : demoId{id} {
    }
    ~constExpression() {}

    int getDemoId() const { return demoId; }
};

int main(){
    constexpr int ans = square(10);
    std::cout<<ans<<"\n";

    std::cout<<cube(ans)<<"\n";

    constexpr constExpression c(10);
    std::cout<<c.getDemoId();
}
//by using constexpr function is called at compile time only not run time 
//it does not call the function at run time
//it moves expression result
//draw backs-- compile time increases

//objdump -Cd file_name.exe