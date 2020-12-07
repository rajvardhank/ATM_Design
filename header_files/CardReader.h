#pragma once
#include <string>
#include "Card.h"

// this class is used by the ATM to read and store the card info. 
class CardReader{

    public:
        std::string cardNumber;
        Date expiryDate;
        int cvv;
        CardStatus cardStatus;
        std::string bankName;
        AccType accType;

    public:
        void readCard(std::string cardName);
        void reset();
};