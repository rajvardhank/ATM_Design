#pragma once
#include <string>
#include "Card.h"
#include "header_files/Screen.h"

enum AccStatus{ accActive, accBlocked, accSuspended};

/*  Base class which cannot be instantiated.
    Stores the banks name, acc #, balance, card.
*/
class Account{
    
    protected:
        std::string bankName;
        std::string accountNumber;
        int accountBalance;
        AccStatus accountStatus;
        int atmWithdrawLimit;
        Card* card;
    
    public:
        Account(std::string name, std::string number, int amount);
        virtual ~Account();
        int getBalance();
        void depositMoney(int amount);

        // Pure virtual method, as savings and checking account have a different implementation of their own.
        virtual bool withdrawMoney(int amount) = 0;
        
        Card* getCard();
};