#include "header_files/Bankobjs.h"

void createbanks(){
    // add a bank you want to create.
    banks["bankA"] = new Bank("bankA");
    banks["bankB"] = new Bank("bankA");
    banks["bankC"] = new Bank("bankA");
}

// add an account in the bank you wish.
// createSavingsAccount(bank name, amount balance in account, atm withdrawal fee)
// createCheckingAccount(bank name, amount balance in account)
void createAccounts(){
    (banks["bankA"])->createSavingsAccount("bankA", 1000, 5);
    (banks["bankA"])->createCheckingAccount("bankA", 500);

    // use this account to test the atm out of money scenario. 
    (banks["bankB"])->createSavingsAccount("bankB", 12000, 10000);
    
    (banks["bankC"])->createCheckingAccount("bankC", 100);
}