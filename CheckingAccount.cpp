#include "header_files/CheckingAccount.h"

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