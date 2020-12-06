#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "CashBin.h"
#include "CardReader.h"
#include "Bankobjs.h"

class Atm{

    private:
        std::string id;
        CashBin* cashBin;
        CardReader cardReader;
        bool pinVerified;

    private:
        void getBalance();
        void depositMoney(int amount);
        void withdrawMoney(int amount); 
        void readCard();   
        bool verifyCard();
        bool verifyPin(std::string pin);

    public:
        Atm();
        ~Atm();
        void doTransaction();
};