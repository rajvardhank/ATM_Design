#include "header_files/Account.h"

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

Account::~Account(){
    delete card;
}