#include "header_files/Bank.h"

Bank::Bank (std::string bankName) : bankName(bankName){
    AccNumberCount = 12345;
}

void Bank::createSavingsAccount(std::string name, int amount, int fee){
    cardNumberToAccounts[std::to_string(AccNumberCount)] = new SavingsAccount(name, std::to_string(AccNumberCount), amount, fee);
    ++AccNumberCount;
}

void Bank::createCheckingAccount(std::string name, int amount){
    cardNumberToAccounts[std::to_string(AccNumberCount)] = new CheckingAccount(name, std::to_string(AccNumberCount), amount);
    ++AccNumberCount;
}

bool Bank::verifyPin(std::string pin, std::string cardNumber){
    cardNumberToAccounts[cardNumber]->getCard()->numTries += 1;
    if (cardNumberToAccounts[cardNumber]->getCard()->numTries > 3) 
    {
        cardNumberToAccounts[cardNumber]->getCard()->changeCardStatus(blocked);
        std::cout<<"Sorry your card is blocked. Please contact the bank.\n";
        return false;
    }    
    else if (cardNumberToAccounts[cardNumber]->getCard()->getPin() == pin)
    {
        cardNumberToAccounts[cardNumber]->getCard()->numTries = 0;
        return true;
    }
    return false;
}

bool Bank::sanctionAmount(std::string cardNumber, int amount){
    return cardNumberToAccounts[cardNumber]->withdrawMoney(amount);
}

void Bank::acceptAmount(std::string cardNumber, int amount){
    cardNumberToAccounts[cardNumber]->depositMoney(amount);
}

int Bank::getBalance (std::string cardNumber){
    return cardNumberToAccounts[cardNumber]->getBalance();
}

bool Bank::checkCardNumExist (std::string cardNumber){
    if (cardNumberToAccounts.find(cardNumber) == cardNumberToAccounts.end()) return false;
    return true;
}

Bank::~Bank(){
    for (auto i: cardNumberToAccounts)
    {
        delete i.second;
    }
}



