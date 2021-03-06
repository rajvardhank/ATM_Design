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
    std::getline(cardFile, line);
    if (line == "savings") accType = savings;
    else if (line == "checking") accType = checking;
    cardFile.close();
}

void CardReader::reset(){
        cardNumber  = "";
        expiryDate.month = 0;
        expiryDate.year = 0;
        expiryDate.day = 0;
        cvv = 0;
        cardStatus = suspended;
        bankName ="";
}