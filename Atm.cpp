#include "header_files/Atm.h"

Atm::Atm(){
    cashBin = new CashBin(10000);
    pinVerified = false;
}

void Atm::readCard(){
    std::cout<<"Please insert card: ";
    std::string cardName;
    std::cin>> cardName;
    cardReader.readCard(cardName);
}

void Atm::getBalance(){
    if (!pinVerified) return;
    int balance = (banks[cardReader.bankName])->getBalance(cardReader.cardNumber);
    std::cout<<"You have $"<<balance<<".00 in your account.\n";
    std::cout<<"Transaction succesfull.\n\nThank You!\n";
    std::cout<<"\n================================\n\n";
}

void Atm::depositMoney(int amount){
    if (!pinVerified) return;
    (banks[cardReader.bankName])->acceptAmount(cardReader.cardNumber,amount);
    cashBin->putCash(amount);
    int balance = (banks[cardReader.bankName])->getBalance(cardReader.cardNumber);
    std::cout<<"\nTransaction succesfull.\n\nYou have $"<<balance<<".00 in your account.\n";
    std::cout<<"Thank You!\n";
    std::cout<<"\n================================\n\n";
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
    std::cout<<"\n================================\n\n";
}

bool Atm::verifyCard(){
    if (banks.find(cardReader.bankName) == banks.end())
    {
        std::cout<<"\nTransaction Failed.\nThis is not a Bank's card. Please enter a valid card.\n";
        std::cout<<"\n================================\n\n";
        return false;
    }
    if (!((banks[cardReader.bankName])->checkCardNumExist(cardReader.cardNumber)))
    {
        std::cout<<"\nTransaction Failed.\nPlease enter a valid card.\n";
        std::cout<<"\n================================\n\n";
        return false;
    }
    std::cout<<"\nYour card is from: "<<cardReader.bankName<<"\n";
    return true;
}

void Atm::readAndVerifyPin()
{
    std::string pin;
    for (int i= 0; i<3; ++i)
    {
        std::cout<<"\nPlease enter your PIN: ";
        std::cin>>pin;
        // sending the pin to bank to verify through bank api
        if ((banks[cardReader.bankName])->verifyPin(pin,cardReader.cardNumber)) 
        {
            pinVerified = true;
            return; 
        }
        else std::cout<<"You entered the wrong Pin.\n";
    }
    if (!pinVerified) (banks[cardReader.bankName])->verifyPin(pin,cardReader.cardNumber);
}

void Atm::selectAccType(){
    char input = '0';
    if (!pinVerified) return;
    std::cout<<"\nPlease select Account type:\n";
    std::cout<<"Savings (You will be charged an ATM withdrawal fee according to your bank rate.) - 1\n";
    std::cout<<"Checking - 2\n";
    while (1)
    {
        std::cin>>input;
        if (input  == '1')
        {
            if (cardReader.accType != savings) 
            {
                std::cout<<"\nSorry, you don't have a savings account associated with this card, redirecting you to your checking account.\n";
            }
            break;
        }
        else if (input  == '2')
        {
            if (cardReader.accType != checking) 
            {
                std::cout<<"\nSorry, you don't have a checking account associated with this card, redirecting you to your savings account.\n";
            }
            break;
        }
        else std::cout<<"Please select a valid option.\n";
    }
}


void Atm::doTransaction(){
    char input;
    int amount;
    std::cout<<"Welcome!\n";
    
    readCard();
    if (!verifyCard()) return;
    if (cardReader.cardStatus != active)
    {
        std::cout<<"Sorry, your card is either blocked or suspended, please contact the bank.\n";
        return;
    } 
    
    readAndVerifyPin();
    if (!pinVerified) return;

    selectAccType();

    while (1)
    {
        std::cout<<"\nWhat would you like to do:\n";
        std::cout<<"Check Balance - 1\n";
        std::cout<<"Deposit Money - 2\n";
        std::cout<<"Withdraw Money - 3\n";
        std::cout<<"Cancel the transaction - 4\n";
        std::cin>>input;
        if (input == '1') 
        {
            getBalance();
            break;
        }
        else if (input == '2') 
        {
            std::cout<<"\nPlease enter the amount you want to deposit: ";
            std::cin>>amount;
            depositMoney(amount);
            break;
        }
        else if (input == '3') 
        {
            std::cout<<"\nPlease enter the amount you want to withdraw: ";
            std::cin>>amount;
            withdrawMoney(amount);
            break;
        }
        else if (input == '4') 
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
