#pragma once

enum CardStatus{ blocked, active, suspended};

enum AccType {savings, checking};

struct Date{
    int day, month, year;
};

// Class used to create a Atm card object.
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
        // variable to keep track of number of failed attempts. That is the user entered wrong pin.
        // After 3 tries, the card is blocked.
        int numTries; 

    public:
        // construtor to generate a new atm card. 
        // it randomly generates a pin and cvv
        Card(std::string cardNumber, std::string bankName, AccType accType);

        // This method is used to store the generated card in .txt format in the "cards" folder.
        // The card is stored as <account number>_<pin>.txt
        // to insert this card during the execution of the app, just enter <account number>_<pin>.
        // This method is invoked when a new account is opened and a corresponding new card is generated.
        // Initially the cards folder is empty, but you can observe that when you execute the .exe file, new 
        // accounts are generated and thus new cards. 
        void storeCardTxt();

        bool isCardValid();
        void changeCardStatus(CardStatus a);
        std::string getPin();
};