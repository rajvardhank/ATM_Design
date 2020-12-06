#include "header_files/Account.h"
#include "header_files/Screen.h"

Account::Account(std::string name, std::string number, int amount) 
                : bankName(name), accountNumber(number), accountBalance(amount) {
                accountStatus = accActive;
                atmWithdrawLimit = 1000;
}

int Account::getBalance(){
    return accountBalance;
}

void Account::depositMoney(int amount){
    accountBalance += amount;
}

Card* Account::getCard(){
    return card;
}


SavingsAccount::SavingsAccount(std::string name, std::string number, int amount,int fee) 
                : Account(name,number,amount), atmTransacftionFee(fee) {
                card = new Card(accountNumber,bankName, savings);
}

bool SavingsAccount::withdrawMoney(int amount){
    if (card->isCardValid())
        if (accountStatus == accActive)
            if (amount <= atmWithdrawLimit)
            {
                if (amount+atmTransacftionFee<=accountBalance)
                {
                    accountBalance -= amount+atmTransacftionFee;
                    Screen::savingsTransactionFee(atmTransacftionFee);
                    return true;
                }
                else Screen::errorLessBalance();
            }
            else Screen::amtMoreThanLimit(atmWithdrawLimit);
        else Screen::accStatus(accountStatus);
    return false;
}

CheckingAccount::CheckingAccount(std::string name, std::string number, int amount) 
                : Account(name,number,amount){
                card = new Card(accountNumber,bankName, checking);
}

bool CheckingAccount::withdrawMoney(int amount){
    if (card->isCardValid())
        if (accountStatus == accActive)
            if (amount <= atmWithdrawLimit)
            {
                if (amount<=accountBalance)
                {
                    accountBalance -= amount;
                    return true;
                }
                else Screen::errorLessBalance();
            }
            else Screen::amtMoreThanLimit(atmWithdrawLimit);
        else Screen::accStatus(accountStatus);
    return false; 
}

Account::~Account(){
    delete card;
}