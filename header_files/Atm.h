#pragma once
#include <string>
#include "CashBin.h"
#include "CardReader.h"
#include "Bankobjs.h"


// This is the atm class used to do the required task.
// No method of the ATM can directly access the customer's account
// It uses the API provided by the bank to do the transaction. 
// eg. for the pin, it send the pin and card number to the respective bank of which the card is
// and gets back the info stating if the pin was right or wrong. 
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

        // Using the above methods it does the transaction. 
        void doTransaction();
};