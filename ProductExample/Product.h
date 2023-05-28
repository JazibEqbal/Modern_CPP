#ifndef PRODUCT_H
#define PRODUCT_H
#include "ProductCategory.h"
#include<iostream>

template<typename T>
class Product
{
private:
    T productId;
    float productPrice;
    enum class ProductCategory productCategory;
public:
    Product() = delete;
    Product(const Product &obj) = default;
    ~Product();
    Product(T id, float price,enum class ProductCategory category);

    T getProductId() const { return productId; }
    void setProductId(const T &productId_) { productId = productId_; }


    float getProductPrice() const { return productPrice; }
    void setProductPrice(float productPrice_) { productPrice = productPrice_; }
    
    // std::string getProductCategory(){
    //     if(productCategory == ProductCategory::FOOD){
    //         return "FOOD";
    //     } else if(productCategory == ProductCategory::KITCHEN_SUPPLIES){
    //         return "KITCHEN_SUPPLIES";
    //     } else {
    //         return "STATIONERY";
    //     }
    // }
    enum class ProductCategory getProductCategory() const {return productCategory;};

    void setProductCategory(enum ProductCategory category){
        if(this->productCategory == ProductCategory::FOOD){
            this->productCategory = ProductCategory::FOOD;
        } else if(this->productCategory == ProductCategory::KITCHEN_SUPPLIES){
            this->productCategory = ProductCategory::KITCHEN_SUPPLIES;
        } else {
            this->productCategory = ProductCategory::STATIONERY;
        }
    }
    friend std::ostream &operator<<(std::ostream &os, Product<T> &prod);
};

template <typename T>
inline Product<T>::~Product()
{
    std::cout<<"Destructor called\n";
}

template <typename T>
inline Product<T>::Product(T id, float price, ProductCategory category) : productId{id}, productPrice{price} ,productCategory{category} {}

template <typename T>
std::ostream &operator<<(std::ostream &os, Product<T> &prod)
{
    os<<"Product Id: "<<prod.getProductId()<<"\n"
      <<"Product price: "<<prod.getProductPrice()<<"\n"
      <<"Product Category: "<<prod.getProductCategory()<<"\n";
}
#endif // PRODUCT_H

