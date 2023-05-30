#include "DebitCard.h"

DebitCard::DebitCard(unsigned long long debNum, int cvv)
: debitCardNumber(debNum),debitCardCVV(cvv) {}

DebitCard::~DebitCard()
{
    std::cout<<"Debit\n";
}

std::ostream &operator<<(std::ostream &os, const DebitCard &rhs) {
    os << "debitCardNumber: " << rhs.debitCardNumber
       << " debitCardCVV: " << rhs.debitCardCVV;
    return os;
}
