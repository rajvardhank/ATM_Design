#include "header_files/Card.h"
#include <fstream>
#include <string>

void Card::storeCardTxt(){
    std::fstream cardFile;
    cardFile.open("cards/"+cardNumber+"_"+pin+".txt",std::ios::out); 
    cardFile<<cardNumber+"\n";   
    cardFile<<std::to_string(expiryDate.month)+"\n";  
    cardFile<<std::to_string(expiryDate.day)+"\n";  
    cardFile<<std::to_string(expiryDate.year)+"\n"; 
    cardFile<<std::to_string(cvv)+"\n"; 
    if (cardStatus == active) cardFile<<"active\n"; 
    if (cardStatus == blocked) cardFile<<"blocked\n"; 
    if (cardStatus == suspended) cardFile<<"susepended\n"; 
    cardFile<<bank+"\n";
    if (accType == savings) cardFile<<"savings\n"; 
    if (accType == checking) cardFile<<"checking\n"; 
    cardFile.close();
}

Card::Card(std::string cardNumber, std::string bankName, AccType accType) 
    : cardNumber(cardNumber), bank(bankName), accType(accType){
        expiryDate.day = rand() % 30 + 1;
        expiryDate.month = rand() % 12 + 1;
        expiryDate.year = 2023;
        cvv = rand() % 900 + 100;
        pin = std::to_string(rand() % 9000 + 1000);
        cardStatus = active;  
        storeCardTxt();
        numTries = 0;
}

bool Card::isCardValid(){
    if (cardStatus == blocked)
    {
        std::cout<<"Sorry your card is blocked.\n";
        return false;
    }
    else if (cardStatus == suspended)
    {
        std::cout<<"Your card is suspended.\n";
        return false;
    }
    return true;
}

void Card::changeCardStatus(CardStatus a){
    cardStatus = a;
}

std::string Card::getPin(){
    return pin;
}
