#ifndef ADDRESS_H
#define ADDRESS_H
#include<iostream>

class Address
{
private:
    std::string addressCity;
    int addressHouseNumber;
    std::string addressStreet;
    int addressZipCode;
    std::string addressState;
public:
    Address() = delete;
    Address(const Address &obj) = default;
    Address(std::string city,int houseNumber,std::string street,int zip,std::string state);
    ~Address();

    std::string getAddressCity() const { return addressCity; }
    void setAddressCity(const std::string &addressCity_) { addressCity = addressCity_; }

    int getAddressHouseNumber() const { return addressHouseNumber; }
    void setAddressHouseNumber(int addressHouseNumber_) { addressHouseNumber = addressHouseNumber_; }

    std::string getAddressStreet() const { return addressStreet; }
    void setAddressStreet(const std::string &addressStreet_) { addressStreet = addressStreet_; }

    int getAddressZipCode() const { return addressZipCode; }
    void setAddressZipCode(int addressZipCode_) { addressZipCode = addressZipCode_; }

    std::string getAddressState() const { return addressState; }
    void setAddressState(const std::string &addressState_) { addressState = addressState_; }

    friend std::ostream &operator<<(std::ostream &os, const Address &rhs);
};


#endif // ADDRESS_H
