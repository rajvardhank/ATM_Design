#include "header_files/Account.h"

Account::Account(std::string name, std::string number, int amount) 
                : bankName(name), accountNumber(number), accountBalance(amount) {
                card = new Card(accountNumber,bankName);
                accountStatus = accActive;
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
                : Account(name,number,amount), atmTransacftionFee(fee) {}

bool SavingsAccount::withdrawMoney(int amount){
    if (card->isCardValid())
        if (accountStatus == accActive)
            if (amount <= atmWithdrawLimit)
            {
                if (amount+atmTransacftionFee<=accountBalance)
                {
                    accountBalance -= amount+atmTransacftionFee;
                    std::cout<<"You have been charged $"<<atmTransacftionFee<<".00 atm transaction fee.\n";
                    return true;
                }
                else std::cout<<"You don't have enough balance in your account.\n";
            }
            else std::cout<<"Please enter an amount below your withdrawal limit of $"<<atmWithdrawLimit<<".00\n";
        else std::cout<<"Your account is either blocked or suspended.\n";
    return false;
}

CheckingAccount::CheckingAccount(std::string name, std::string number, int amount) 
                : Account(name,number,amount){}

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
                else std::cout<<"You don't have enough balance in your account.\n";
            }
            else std::cout<<"Please enter an amount below your withdrawal limit of $"<<atmWithdrawLimit<<".00\n";
        else std::cout<<"Your account is either blocked or suspended.\n";
    return false; 
}

Account::~Account(){
    delete card;
}