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
    std::cout<<"Transaction succesfull.\nThank You!\nPress any key to continue.\n";
    std::cin>>balance;
}

void Atm::depositMoney(int amount){
    if (!pinVerified) return;
    int balance = (banks[cardReader.bankName])->getBalance(cardReader.cardNumber);
    (banks[cardReader.bankName])->acceptAmount(cardReader.cardNumber,amount);
    cashBin->putCash(amount);
    std::cout<<"\nTransaction succesfull.\nYou have $"<<balance<<".00 in your account.\n";
    std::cout<<"Thank You!\nPress any key to continue.\n";
    std::cin>>balance;
}

void Atm::withdrawMoney(int amount){
    if (!pinVerified) return;
    int balance;
    if (cashBin->dispenseCash(amount))
    {
    bool status = (banks[cardReader.bankName])->sanctionAmount(cardReader.cardNumber,amount);
    balance = (banks[cardReader.bankName])->getBalance(cardReader.cardNumber);
    std::cout<<"\nTransaction succesfull.\nYou have $"<<balance<<".00 in your account.\n";
    }
    else
    {
        std::cout<<"\nTransaction Failed, sorry the atm is out of money.";
    }
    std::cout<<"Thank You!\nPress any key to continue.\n";
    std::cin>>balance;
}

bool Atm::verifyCard(){
    int temp;
    if (banks.find(cardReader.bankName) == banks.end())
    {
        std::cout<<"Transaction Failed.\nThis is not a Bank's card. Please enter a valid card.\n";        
        std::cout<<"Press any key to continue.\n";  
        std::cin>>temp; 
        return false;
    }
    if (!((banks[cardReader.bankName])->checkCardNumExist(cardReader.cardNumber)))
    {
        std::cout<<"Transaction Failed.\nPlease enter a valid card.\n";        
        std::cout<<"Press any key to continue.\n";  
        std::cin>>temp; 
        return false;
    }
    return true;
}

bool Atm::verifyPin(std::string pin)
{
    bool isRight = (banks[cardReader.bankName])->verifyPin(pin,cardReader.cardNumber); // sending the pin to bank to verify through bank api 
    if (!isRight)
    {
        std::cout<<"\nTransaction Failed.\nYou entered the wrong Pin.\n";
        std::cout<<"Press any key to continue.\n";  
        std::cin>>isRight; 
        pinVerified = false;  
        return false;  
    }
    pinVerified = true;
    return true;
}

void Atm::doTransaction(){
    int input;
    std::cout<<"Welcome!\n";
    readCard();
    if (!verifyCard()) return;

    std::cout<<"Please enter your PIN: ";
    std::string pin;
    std::cin>>pin;
    if (!verifyPin(pin)) return;

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
}

Atm::~Atm(){
    delete cashBin;
}
