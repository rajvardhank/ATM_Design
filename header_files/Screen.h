#pragma once
#include <iostream>


// This class is used to print to the screen
class Screen{

    public:
        static void newLine();
        static void welcome();
        static void exitAtm();
        static void bankName(std::string bankName);
        static void cardStatus(int status);
        static void accStatus(int status);
        static void enterPin();
        static void errorPin();
        static void accSelection();
        static void notRightAccount(std::string right, std::string wrong);
        static void selectValidOption();
        static void transactionOptions();
        static void deposit();
        static void withdraw();
        static void savingsTransactionFee(int atmTransacftionFee);
        static void errorLessBalance();
        static void amtMoreThanLimit(int amount, int atmWithdrawLimit);
        static void pinFailedAttempts();
        static void transactionSuccefull(int prevbalance, int balance);
        static void transactionFailed(int balance, std::string error);
        static void collectMoney();
};