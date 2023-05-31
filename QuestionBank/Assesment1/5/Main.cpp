#include <iostream>
#include "Account.h"
#include "Bank.h"
#include <list>
#include "AccountType.h"
#include "functionalities.h"

<<<<<<< Updated upstream
int main(){
    DebitCard *d1 = new DebitCard(123456789,123);
    DebitCard *d2 = new DebitCard(786868686,786);
    Account *a1 = new Account("Ja", 23,ACCOUNT_TYPE::CURRENT,d1);
    Account *a2 = new Account("Kya", 322223,ACCOUNT_TYPE::SAVINGS,d2);
    std::list<Account*> list = {a1,a2};
    Bank *bank = new Bank("SBI","SBIXXX0GAYA",BANK_CATEGORY::NATIONALIZIED,list);
    //std::cout<<d1->getDebitCardCVV(); 
    //std::cout<<a1->getAccountDebitCard()->getDebitCardNumber();
    std::cout<<"Does account exists? "<<FindAccountByDebitCardNumber(list,1234526789)<<"\n";
    std::cout<<"Highest account balance: "<<FindHighestAccountBalance(list)<<"\n";
    std::cout<<"Count of Account is: "<<FindCountOfAccountBelowThreshold(list,700)<<"\n";

    delete d1,d2;
    for(auto* it: list){
        delete it;
    }
    delete bank;

=======
int main()
{
    // DebitCard *d1 = new DebitCard(123456789,123);

    // std::cout<<d1->getDebitCardCVV();
>>>>>>> Stashed changes
    return 0;
}
