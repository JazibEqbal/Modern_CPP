#include "Product.h"
#include <iostream>

enum class ProductCategory category()
{
    std::cout << "Choose 1 for FOOD\n"
              << "Choose 2 for KITCHEN_SUPPLIES\n"
              << "Choose 3 for STATIONERY\n";
    int choice;
    std::cin >> choice;
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
};

Product<int> *arr[5];

void Initializer()
{
    Product<int> *p1 = new Product<int>(1, 240.5, ProductCategory::FOOD);
    Product<int> *p2 = new Product<int>(2, 530, ProductCategory::KITCHEN_SUPPLIES);
    Product<int> *p3 = new Product<int>(3, 540.5, ProductCategory::FOOD);
    Product<int> *p4 = new Product<int>(13, 20.5, ProductCategory::FOOD);
    Product<int> *p5 = new Product<int>(32, 40.5, ProductCategory::FOOD);

    arr[0] = {p1};
    arr[1] = {p2};
    arr[2] = {p3};
    arr[3] = {p4};
    arr[4] = {p5};
}

float CalculateTotalPrice(Product<int> *a)
{
    float sum = 0;
    for (int i = 0; i < 5; i++){
        sum += arr[i]->getProductPrice();
    }
    return sum;
}

int main()
{
    // for(int i=0;i<2;i++){
    //     enum ProductCategory ans = category();
    //     int id;
    //     std::cin>>id;
    //     float price;
    //     std::cin>>price;
    //     arr[i]=new Product<int>(id,price,ans);
    // }
    Initializer();

    std::cout << CalculateTotalPrice(*arr) << "\n";

    for(int i=0;i<5;i++){
        delete arr[i];
    }
    return 0;
}