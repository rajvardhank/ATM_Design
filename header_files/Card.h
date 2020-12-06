#pragma once
#include <iostream>

enum CardStatus{ blocked, active, suspended};

struct Date{
    int day, month, year;
};

class Card{

    private:
        std::string cardNumber;
        Date expiryDate;
        int cvv;
        std::string pin;
        CardStatus cardStatus;
        std::string bank;

    public:
        int numTries;

    public:
        Card(std::string cardNumber, std::string bankName);
        void storeCardTxt();
        bool isCardValid();
        void changeCardStatus(CardStatus a);
        std::string getPin();
};