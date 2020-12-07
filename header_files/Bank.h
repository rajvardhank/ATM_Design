#pragma once
#include "unordered_map"
#include "Account.h"
#include "SavingsAccount.h"
#include "CheckingAccount.h"

class Bank{

    private:
        std::string bankName;

        //A static counter is maintained to generate unique account numbers accross 
        //all the banks when a new account is opened. 
        // for simplicity card number is same as acc number
        static int AccNumberCount; 

        std::unordered_map<std::string, Account*> cardNumberToAccounts;

    public:
        Bank (std::string bankName);
        ~Bank();
        void createSavingsAccount(std::string name, int amount, int fee);
        void createCheckingAccount(std::string name, int amount);

        // Banks API to accept pin from atm and return a boolean. 
        bool verifyPin(std::string pin, std::string cardNumber);

        // Banks API to see if the requested amount is within withdrawal limit
        // and to see is the card and account is active and then sanction the amount.
        bool sanctionAmount(std::string cardNumber, int amount);
        int getTransactionFee(std::string cardNumber);
        
        void acceptAmount(std::string cardNumber, int amount);
        int getBalance (std::string cardNumber);
        bool checkCardNumExist (std::string cardNumber);
};


