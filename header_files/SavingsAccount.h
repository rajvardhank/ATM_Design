#pragma once
#include "Account.h"


/*
    Is inherited from Class Account, 
    defines the withdrawMoney method and 
    charges an atm withdrawal fee.
*/
class SavingsAccount: public Account{

    private:
        int atmTransacftionFee;

    public: 
        SavingsAccount(std::string name, std::string number, int amount, int fee);
        bool withdrawMoney(int amount);
        int getFee();
};