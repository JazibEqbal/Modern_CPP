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
    //friend std::ostream &operator<<(std::ostream &os, Product &pro);

    T getProductId(){
        return productId;
    }
    void setProductId(T id){
        productId = id;
    }

    float getProductPrice() const { return productPrice; }
    void setProductPrice(float productPrice_) { productPrice = productPrice_; }
    
    std::string getProductCategory(){
        if(productCategory == ProductCategory::FOOD){
            return "FOOD";
        } else if(productCategory == ProductCategory::KITCHEN_SUPPLIES){
            return "KITCHEN_SUPPLIES";
        } else {
            return "STATIONERY";
        }
    }

    void setProductCategory(enum ProductCategory category){
        if(this->productCategory == ProductCategory::FOOD){
            this->productCategory = ProductCategory::FOOD;
        } else if(this->productCategory == ProductCategory::KITCHEN_SUPPLIES){
            this->productCategory = ProductCategory::KITCHEN_SUPPLIES;
        } else {
            this->productCategory = ProductCategory::STATIONERY;
        }
    }
};

#endif // PRODUCT_H
