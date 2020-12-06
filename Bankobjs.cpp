#include "header_files/Bankobjs.h"

void createbanks(){
    // add a bank you want to create.
    banks["bankA"] = new Bank("bankA");
    banks["bankB"] = new Bank("bankA");
    banks["bankC"] = new Bank("bankA");
}

void createAccounts(){
    // add an account in the bank you wish.
    // createSavingsAccount(bank name, amount balance in account, atm withdrawal fee)
    (banks["bankA"])->createSavingsAccount("bankA", 1000, 5);
    (banks["bankA"])->createCheckingAccount("bankA", 500);
    (banks["bankB"])->createSavingsAccount("bankB", 200, 10);
    (banks["bankB"])->createCheckingAccount("bankB", 5000);
    (banks["bankC"])->createSavingsAccount("bankC", 100, 2);
}