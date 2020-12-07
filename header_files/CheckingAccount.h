#pragma once
#include "Account.h"

/*
    Is inherited from Class Account, 
    defines the withdrawMoney method.
*/
class CheckingAccount: public Account{

    public: 
        CheckingAccount(std::string name, std::string number, int amount);
        bool withdrawMoney(int amount);
};