#include "Product.h"
#include<iostream>

Product<int> *arr[5];

enum class ProductCategory category(){
    std::cout<<"Choose 1 for FOOD\n"
             <<"Choose 2 for KITCHEN_SUPPLIES\n"
             <<"Choose 3 for STATIONERY\n";
    int choice;
    std::cin>>choice;
    switch (choice)
    {
    case 1:
        return ProductCategory::FOOD;
        break;
    case 2:
        return ProductCategory::KITCHEN_SUPPLIES;
        break;
    case 3:
        return ProductCategory::STATIONERY;
        break;
    default:
        return ProductCategory::STATIONERY;
        break;
    }            
}

int CalculateTotalPrice(){
    int sum=0;
    for(int i=0;i<5;i++){
         sum += arr[i]->getProductPrice();
    }
}

int main(){
    Product<int> *p1 = new Product<int>(1,40.5,ProductCategory::FOOD);
    //Product<double> *p2 = new Product<double>(2.2,30,ProductCategory::KITCHEN_SUPPLIES);
    //Product<std::string> *p3 = new Product<std::string>("3x",40.5,ProductCategory::FOOD);
    Product<int> *p4 = new Product<int>(13,20.5,ProductCategory::FOOD);
    Product<int> *p5 = new Product<int>(32,40.5,ProductCategory::FOOD);

    arr[0] = {p1};
    arr[1] = {p1};
    arr[2] = {p4};
    arr[3] = {p4};
    arr[4] = {p5};

    std::cout<<CalculateTotalPrice();
    return 0;
}