#ifndef USER_H
#define USER_H
#include<iostream>

class User
{
private:
    std::string userId;
    int userAge;
    float userIncome;
public:
    User() = delete;
    User(const User &obj) = default;
    User(std::string id,int age,float income);
    ~User();
    //getters and setters
    std::string getUserId() const { return userId; }
    void setUserId(const std::string &userId_) { userId = userId_; }

    int getUserAge() const { return userAge; }
    void setUserAge(int userAge_) { userAge = userAge_; }

    float getUserIncome() const { return userIncome; }
    void setUserIncome(float userIncome_) { userIncome = userIncome_; }
    //functionto add and return userIncome of two users
    float operator+(const User &obj);
    //friend function to display user
    friend std::ostream &operator<<(std::ostream &os, const User &rhs);
};

#endif // USER_H
