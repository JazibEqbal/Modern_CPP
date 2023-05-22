#include "Product.h"

template <typename T>
Product<T>::~Product()
{
    std::cout<<"Destructor called\n";
}

template <typename T>
Product<T>::Product(T id, float price, ProductCategory category): productId{id}, productPrice{price} ,productCategory{category}{}

