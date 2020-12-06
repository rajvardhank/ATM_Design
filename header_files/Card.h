#pragma once

enum CardStatus{ blocked, active, suspended};

enum AccType {savings, checking};

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
        AccType accType;

    public:
        int numTries;

    public:
        Card(std::string cardNumber, std::string bankName, AccType accType);
        void storeCardTxt();
        bool isCardValid();
        void changeCardStatus(CardStatus a);
        std::string getPin();
};