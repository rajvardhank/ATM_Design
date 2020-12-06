#pragma once
#include "unordered_map"
#include "Account.h"

class Bank{

    private:
        std::string bankName;
        static int AccNumberCount; // for simplicity card number is same as acc number
        std::unordered_map<std::string, Account*> cardNumberToAccounts;

    public:
        Bank (std::string bankName);
        ~Bank();
        void createSavingsAccount(std::string name, int amount, int fee);
        void createCheckingAccount(std::string name, int amount);
        bool verifyPin(std::string pin, std::string cardNumber);
        bool sanctionAmount(std::string cardNumber, int amount);
        void acceptAmount(std::string cardNumber, int amount);
        int getBalance (std::string cardNumber);
        bool checkCardNumExist (std::string cardNumber);
};


