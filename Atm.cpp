#include "header_files/Atm.h"

Atm::Atm(){
    cashBin = new CashBin(10000);
    pinVerified = false;
}

void Atm::readCard(){
    std::cout<<"Please insert card.\n";
    std::string cardName;
    std::cin>> cardName;
    cardReader.readCard(cardName);
}

void Atm::getBalance(){
    if (!pinVerified) return;
    int balance = (banks[cardReader.bankName])->getBalance(cardReader.cardNumber);
    std::cout<<"You have $"<<balance<<".00 in your account.\n";
    std::cout<<"Transaction succesfull.\n\nThank You!\n";
    std::cout<<"\n================================\n================================\n\n";
}

void Atm::depositMoney(int amount){
    if (!pinVerified) return;
    int balance = (banks[cardReader.bankName])->getBalance(cardReader.cardNumber);
    (banks[cardReader.bankName])->acceptAmount(cardReader.cardNumber,amount);
    cashBin->putCash(amount);
    std::cout<<"\nTransaction succesfull.\n\nYou have $"<<balance<<".00 in your account.\n";
    std::cout<<"Thank You!\n";
    std::cout<<"\n================================\n================================\n\n";
}

void Atm::withdrawMoney(int amount){
    if (!pinVerified) return;
    int balance;
    if (cashBin->dispenseCash(amount))
    {
    bool status = (banks[cardReader.bankName])->sanctionAmount(cardReader.cardNumber,amount);
    balance = (banks[cardReader.bankName])->getBalance(cardReader.cardNumber);
    if (status) std::cout<<"\nTransaction succesfull.\nPlease Collect your money.\n\nYou have $"<<balance<<".00 in your account.\n";
    else std::cout<<"Transaction failed.\n\nYou have $"<<balance<<".00 in your account.\n";
    }
    else
    {
        std::cout<<"\nTransaction Failed, sorry the atm is out of money.";
    }
    std::cout<<"Thank You!\n";
    std::cout<<"\n================================\n================================\n\n";
}

bool Atm::verifyCard(){
    if (banks.find(cardReader.bankName) == banks.end())
    {
        std::cout<<"\nTransaction Failed.\nThis is not a Bank's card. Please enter a valid card.\n";
        std::cout<<"\n================================\n================================\n\n";
        return false;
    }
    if (!((banks[cardReader.bankName])->checkCardNumExist(cardReader.cardNumber)))
    {
        std::cout<<"\nTransaction Failed.\nPlease enter a valid card.\n";
        std::cout<<"\n================================\n================================\n\n";
        return false;
    }
    return true;
}

bool Atm::verifyPin(std::string pin)
{
    bool isRight = (banks[cardReader.bankName])->verifyPin(pin,cardReader.cardNumber); // sending the pin to bank to verify through bank api 
    if (!isRight) return false; 
    pinVerified = true;
    return true;
}

void Atm::doTransaction(){
    int input;
    std::cout<<"Welcome!\n";
    readCard();
    if (!verifyCard()) return;
    if (cardReader.cardStatus != active)
    {
        std::cout<<"Sorry, your card is either blocked or suspended, please contact the bank.\n";
        return;
    } 
    
    std::string pin;
    for (int i= 0; i<3; ++i)
    {
        std::cout<<"\nPlease enter your PIN: ";
        std::cin>>pin;
        if (verifyPin(pin)) break;
        else std::cout<<"You entered the wrong Pin.\n";
    }
    if (!pinVerified) 
    {
        verifyPin(pin);
        return;
    }

    while (1)
    {
        std::cout<<"\nWhat would you like to do:\n";
        std::cout<<"Check Balance - 1\n";
        std::cout<<"Deposit Money - 2\n";
        std::cout<<"Withdraw Money - 3\n";
        std::cout<<"Cancel the transaction - 4\n";
        std::cin>>input;
        if (input == 1) 
        {
            getBalance();
            break;
        }
        else if (input == 2) 
        {
            std::cout<<"Please enter the amount you want to deposit: ";
            std::cin>>input;
            depositMoney(input);
            break;
        }
        else if (input == 3) 
        {
            std::cout<<"Please enter the amount you want to withdraw: ";
            std::cin>>input;
            withdrawMoney(input);
            break;
        }
        else if (input == 4) 
        {
            cardReader.reset();
            break;
        }
        else
        {
            std::cout<<"Please select a valid option.\n";
        }
    }
    pinVerified = false;
    cardReader.reset();
}

Atm::~Atm(){
    delete cashBin;
}
