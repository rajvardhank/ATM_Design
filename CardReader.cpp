#include "header_files/CardReader.h"
#include <fstream>
#include <sstream>

void CardReader::readCard(std::string cardName){
    std::fstream cardFile;
    std::stringstream temp;
    int temp2;
    cardFile.open("cards/"+cardName+".txt",std::ios::in);
    std::string line;
    std::getline(cardFile, line);
    cardNumber = line;
    std::getline(cardFile, line);
    temp << line;
    temp >> temp2;
    expiryDate.month = temp2;
    std::getline(cardFile, line);
    temp << line;
    temp >> temp2;
    expiryDate.day = temp2;
    std::getline(cardFile, line);
    temp << line;
    temp >> temp2;
    expiryDate.year = temp2;
    std::getline(cardFile, line);
    temp << line;
    temp >> temp2;
    cvv = temp2;
    std::getline(cardFile, line);
    if (line == "active") cardStatus = active;
    else if (line == "blocked") cardStatus = blocked;
    else if (line == "suspended") cardStatus = suspended;
    std::getline(cardFile, line);
    bankName = line;
    cardFile.close();
}

void CardReader::reset(){
        cardNumber  = "";
        expiryDate.month = 0;
        expiryDate.year = 0;
        expiryDate.day = 0;
        cvv = 0;
        cardStatus = active;
        bankName ="";
}

void CardReader::showCardDetails(){
    std::cout<<"Card Details:\n";
    std::cout<<"card Number: "<<cardNumber<<"\n";
    std::cout<<"Expiry Date: "<<expiryDate.month<<"/"<<expiryDate.day<<"/"<<expiryDate.year<<"\n";
    std::cout<<"CVV: ***\n";
    std::cout<<"Card Status: "<<cardStatus<<"\n";
    std::cout<<"================================\n================================\n";
}