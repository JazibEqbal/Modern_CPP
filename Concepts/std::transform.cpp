#include<iostream>
#include<algorithm>
#include<vector>


class x
{
private:
    std::vector<float> iv;
    double tax;
public:
    x(std::vector<float> &&v,double t) : iv{v}, tax{t} { }
    ~x() {}

    double getTax() const { return tax; }
    void setTax(double tax_) { tax = tax_; }

    std::vector<float> getIv() const { return iv; }
    void setIv(const std::vector<float> &iv_) { iv = iv_; }
    
};

int main(){
     x xx(std::vector<float>{100.0f,200.0f,300.0f},18);

     double tax = xx.getTax();
     auto data = xx.getIv();
     auto plusTax = [tax] (float value){return value * (1+tax);};

        std::vector<double> res(xx.getIv().size());
        std::transform(data.begin(),
                        data.end(),
                        res.begin(),
                        plusTax
        );
    for(auto &it: res){
        std::cout<<it<<" ";
    }
}
