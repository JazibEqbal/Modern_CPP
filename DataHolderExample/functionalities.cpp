#include "DataHolder.h"
#include<iostream>

template<typename T>
T displayFirst(std::list<T> &val){
    if(val.empty()){
        throw std::runtime_error("Sorry. List passed is empty");
    }
    return val.front();
}

// template<typename T>
// T findElementAtGivenPosition(std::list<T> &val,int position){
//     //return val[position];    // directly accessing position from values using operator [] //doesn't work
//         std::list<T>::iterator it = val.begin();
//         // std::advance(it,position);
//         // return *it;
//         return *(it+position);
// }

template<typename T>
T findElementAtGivenPosition(std::list<T> &val,int position){
    if(position  >= val.size() || position < 0 ){
        throw std::runtime_error("Invalid Position");
    }
    if(val.empty()){
        throw std::runtime_error("Sorry. List passed is empty");
    }
    std::list<T>::iterator it = val.begin();
    return *(it+position);
}

// template<typename T>
// T display(std::list<T> & val){
//     try
//     {
//         if(val.empty()){
//             throw e;
//         }
//         return val.front();
//     }
//     catch(const std::exception& e)
//     {
//         //std::cerr << e.what() << '\n';
//         std::cout<<"Empty\n";
//     }
// }

template<typename T>
bool searchElement(std::list<T> &val, T item){
    if(val.empty()){
        throw std::runtime_error("Sorry. List passed is empty");
    }
    for(T element: val){
        if(element == item){
            return true;
        }
    }
    return false;
}