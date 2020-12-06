#pragma once
#include <iostream>
#include <string>
#include "Card.h"


class CardReader{

    public:
        std::string cardNumber;
        Date expiryDate;
        int cvv;
        CardStatus cardStatus;
        std::string bankName;

    public:
        void readCard(std::string cardName);
        void reset();
        void showCardDetails();
};