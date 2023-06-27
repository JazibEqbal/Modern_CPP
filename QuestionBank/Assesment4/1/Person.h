#ifndef PERSON_H
#define PERSON_H
#include<iostream>
#include "LoanIntent.h"

class Person
{
//DATA MEMBERS
private:
    int person_age;
    int person_income;
    INTENT_TYPE loan_intent;
    int loan_amnt;
    float loan_int_rate;
    bool loan_status;
//DATA MEMBER FUNCTIONS
public:
    Person() = delete;                  // default deleted constructor
    Person(const Person&) = default;    //default copy constructor
    Person(int age,int income,INTENT_TYPE type,int amount,float rate,bool status); //user defined constructor
    ~Person();                     // Destructor

    //GETTERS & SETTERS
    int personAge() const { return person_age; }
    void setPersonAge(int personAge) { person_age = personAge; }

    int personIncome() const { return person_income; }
    void setPersonIncome(int personIncome) { person_income = personIncome; }

    int loanAmnt() const { return loan_amnt; }
    void setLoanAmnt(int loanAmnt) { loan_amnt = loanAmnt; }

    float loanIntRate() const { return loan_int_rate; }
    void setLoanIntRate(float loanIntRate) { loan_int_rate = loanIntRate; }

    bool isLoanStatus() const { return loan_status; }
    void setLoanStatus(bool loanStatus) { loan_status = loanStatus; }

    INTENT_TYPE getIntent() const { return loan_intent;};

    //friend function to display all data of a object
    friend std::ostream &operator<<(std::ostream &os, const Person &rhs);
};
//function to display categorical data
std::string displayLoanIntent(INTENT_TYPE type);


#endif // PERSON_H
