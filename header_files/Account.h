#pragma once
#include <string>
#include <iostream>
#include "Card.h"

enum AccStatus{ accActive, accBlocked, accSuspended};

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
        virtual bool withdrawMoney(int amount) = 0;
        Card* getCard();
};

class SavingsAccount: public Account{

    private:
        int atmTransacftionFee;

    public: 
        SavingsAccount(std::string name, std::string number, int amount, int fee);
        bool withdrawMoney(int amount);
};

class CheckingAccount: public Account{

    public: 
        CheckingAccount(std::string name, std::string number, int amount);
        bool withdrawMoney(int amount);
};