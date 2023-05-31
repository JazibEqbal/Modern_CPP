#ifndef DEBITCARD_H
#define DEBITCARD_H
#include<iostream>
class DebitCard
{
private:
    unsigned long long debitCardNumber;
    int debitCardCVV;
public:
    DebitCard() = delete;
    DebitCard(const DebitCard &obj) = delete;
    DebitCard(unsigned long long debNum, int cvv);
    ~DebitCard();

    unsigned long long getDebitCardNumber() const { return debitCardNumber; }
    void setDebitCardNumber(unsigned long long debitCardNumber_) { debitCardNumber = debitCardNumber_; }

    int getDebitCardCVV() const { return debitCardCVV; }
    void setDebitCardCVV(int debitCardCVV_) { debitCardCVV = debitCardCVV_; }

    friend std::ostream &operator<<(std::ostream &os, const DebitCard &rhs);

};


#endif // DEBITCARD_H
