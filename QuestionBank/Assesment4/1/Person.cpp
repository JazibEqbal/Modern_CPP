#include "Person.h"

// user defined constructor
Person::Person(int age, int income, INTENT_TYPE type, int amount, float rate, bool status)
    : person_age{age}, person_income{income}, loan_intent{type}, loan_amnt{amount}, loan_int_rate{rate}, loan_status{status} {}

// destructor
Person::~Person()
{
    std::cout << "Des\n";
}
// friend function to display all data of a object
std::ostream &operator<<(std::ostream &os, const Person &rhs)
{
    os << "person_age: " << rhs.person_age
       << " person_income: " << rhs.person_income
       << " loan_intent: " << displayLoanIntent(rhs.loan_intent)
       << " loan_amnt: " << rhs.loan_amnt
       << " loan_int_rate: " << rhs.loan_int_rate
       << " loan_status: " << rhs.loan_status;
    return os;
}

// function to display categorical data
std::string displayLoanIntent(INTENT_TYPE type)
{
    if (type == INTENT_TYPE::MEDICAL)
    {
        return "MEDICAL";
    }
    else if (type == INTENT_TYPE::PERSONAL)
    {
        return "PERSONAL";
    }
    else if (type == INTENT_TYPE::EDUCATION)
    {
        return "EDUCATION";
    }
    else
    {
        return "VENTURE";
    }
}