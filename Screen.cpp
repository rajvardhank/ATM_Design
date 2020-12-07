#include "header_files/Screen.h"


void Screen::newLine(){
    std::cout<<"\n================================\n\n";
}

void Screen::welcome(){
    std::cout<<"Welcome!\n";
    std::cout<<"Please insert card: ";
}

void Screen::exitAtm(){
    std::cout<<"Please press 0 to exit ATM or any other key to do another transaction.\n";
}

void Screen::bankName(std::string bankName)
{
    std::cout<<"\nYour card is from: " + bankName + "\n";
}

void Screen::cardStatus(int status)
{
    std::string s;
    if (status == 0) s = "blocked";
    if (status == 1) s = "active";
    if (status == 2) s = "suspended";
    std::cout<<"\nYour card is " + s + ", please contact the bank if you need any help.\n";
}

void Screen::accStatus(int status)
{
    std::string s;
    if (status == 0) s = "active";
    if (status == 1) s = "blocked";
    if (status == 2) s = "suspended";
    std::cout<<"\nYour account is " + s + ", please contact the bank if you need any help.\n";
}

void Screen::enterPin(){
    std::cout<<"\nPlease enter your PIN: ";
}

void Screen::errorPin(){
    std::cout<<"\nYou entered the wrong Pin.\n";
}

void Screen::accSelection(){
    std::cout<<"\nPlease select Account type:\n";
    std::cout<<"Savings (You will be charged an ATM withdrawal fee according to your bank rate.) - 1\n";
    std::cout<<"Checking - 2\n";
}

void Screen::notRightAccount(std::string right, std::string wrong){
    std::cout<<"\nSorry, you don't have a " +wrong+  " account associated with this card, redirecting you to your " +right+  " account.\n";
}

void Screen::selectValidOption(){
    std::cout<<"Please select a valid option.\n";
}

void Screen::transactionOptions(){
        std::cout<<"\nWhat would you like to do:\n";
        std::cout<<"Check Balance - 1\n";
        std::cout<<"Deposit Money - 2\n";
        std::cout<<"Withdraw Money - 3\n";
        std::cout<<"Cancel the transaction - 4\n";
}

void Screen::deposit(){
    std::cout<<"\nPlease enter the amount you want to deposit: ";
}

void Screen::withdraw(){
    std::cout<<"\nPlease enter the amount you want to withdraw: ";
}

void Screen::savingsTransactionFee(int atmTransacftionFee){
    std::cout<<"\nYou have been charged $"<<atmTransacftionFee<<".00 atm transaction fee for your savings account.\n";
}

void Screen::errorLessBalance(){
    std::cout<<"\nYou don't have enough balance in your account.\n";
}

void Screen::amtMoreThanLimit(int atmWithdrawLimit){
    std::cout<<"\nThe amount you entered is more than your withdrawal limit of $"<<atmWithdrawLimit<<".00\n";
}

void Screen::pinFailedAttempts(){
    std::cout<<"Sorry your card is blocked due to 3 failed attempts. Please contact the bank.\n";
}

void Screen::transactionSuccefull(int prevbalance, int balance){
    std::cout<<"\nTransaction succesfull.\n\nYou had $"<<prevbalance<<".00 in your account, your new balance is $"<<balance<<".00 .\n";
    std::cout<<"Thank You!\n";
}

void Screen::transactionFailed(int balance, std::string error){
    if (balance != -1) std::cout<<"\nTransaction failed. " + error + "\n\nYou have $"<<balance<<".00 in your account.\n";
    else std::cout<<"\nTransaction failed. " + error + "\n";
    std::cout<<"Thank You!\n";
}

void Screen::collectMoney(){
    std::cout<<"Please collect your money";
}