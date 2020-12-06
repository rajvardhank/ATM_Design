#include "header_files/Bankobjs.h"

void createAccounts(){
    banks["bankA"]->createSavingsAccount("bankA", 1000, 5);
    banks["bankA"]->createCheckingAccount("bankA", 500);
    banks["bankB"]->createSavingsAccount("bankB", 200, 10);
    banks["bankB"]->createCheckingAccount("bankB", 5000);
    banks["bankC"]->createSavingsAccount("bankC", 100, 2);
}