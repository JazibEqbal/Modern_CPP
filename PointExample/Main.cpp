#include "Point.h"

int main(){
    Point p1(2,3);
    Point p2(3,4);
    Point p3 = p1 + p2;
    std::cout<<"Addition of two point is\n";
    std::cout<<p3<<"\n";
    Point p4(2,3);
    Point p5(3,4);
    std::cout<<"Substraction of two point is\n";
    Point p6 = p4 - p5;
    std::cout<<p6<<"\n";
    Point p7 = p1++;
    std::cout<<"Adding 1 to point is\n";
    std::cout<<p7<<"\n";
}