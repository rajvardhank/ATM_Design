#pragma once
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
        void readAndVerifyPin();
        void selectAccType();

    public:
        Atm();
        ~Atm();
        void doTransaction();
};