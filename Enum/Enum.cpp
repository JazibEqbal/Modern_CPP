// //Enums are used to store categorical data.

// #include<iostream>

// enum Gear{
//     FIRST,
//     SECOND,
//     THIRD,
//     FOURTH,
//     FIFTH,
//     REVERSE
// };

// enum Color{
//     RED,
//     GREEN,
//     BLUE,
// };

//   void fun(int val){
//     //....
// };
// int main(){
//     enum Gear g1 = Gear::FIRST;
    //    enum Color c1 = Color::RED;
    //    std::cout<< (g1 == c1);
    //    int n1 = (int) g1;
// };

// ENUM CLASS

#include<iostream>

enum class Gear : int {
    FIRST,
    SECOND,
    THIRD,
    FOURTH,
    FIFTH,
    REVERSE
};

enum class Color : char {
    R,
    G,
    B
};

void fun(int val){
    //something
}

int main(){
    enum class Gear g1 = Gear::FIRST;
    enum class Color c1 = Color::R;
    std::cout<< (g1 == c1);
    fun(c1);
}