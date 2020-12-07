#include "header_files/Atm.h"
#include "header_files/Screen.h"

Atm::Atm(){
    cashBin = new CashBin(10000); // an atm is instantiated with $10000 in its account
    pinVerified = false;
}

void Atm::readCard(){
    std::string cardName;
    std::cin>> cardName;
    cardReader.readCard(cardName);
}

void Atm::getBalance(){
    if (!pinVerified) return;
    int balance = (banks[cardReader.bankName])->getBalance(cardReader.cardNumber);
    Screen::transactionSuccefull(balance,balance);
    Screen::newLine();
}

void Atm::depositMoney(int amount){
    if (!pinVerified) return;
    int prevbalance = (banks[cardReader.bankName])->getBalance(cardReader.cardNumber);
    (banks[cardReader.bankName])->acceptAmount(cardReader.cardNumber,amount);
    cashBin->putCash(amount);
    int balance = (banks[cardReader.bankName])->getBalance(cardReader.cardNumber);
    Screen::transactionSuccefull(prevbalance,balance);
    Screen::newLine();
}

void Atm::withdrawMoney(int amount){
    if (!pinVerified) return;
    int prevbalance = (banks[cardReader.bankName])->getBalance(cardReader.cardNumber);
    int balance = (banks[cardReader.bankName])->getBalance(cardReader.cardNumber);
    amount += (banks[cardReader.bankName])->getTransactionFee(cardReader.cardNumber);
    if (cashBin->dispenseCash(amount))
    {
        bool status = (banks[cardReader.bankName])->sanctionAmount(cardReader.cardNumber,amount);
        balance = (banks[cardReader.bankName])->getBalance(cardReader.cardNumber);
        if (status) 
        {
            Screen::collectMoney();
            Screen::transactionSuccefull(prevbalance,balance);
        }
        else Screen::transactionFailed(balance, "");
    }
    else Screen::transactionFailed(balance, "sorry the atm doesn't have enough money");
    Screen::newLine();
}

bool Atm::verifyCard(){
    if (banks.find(cardReader.bankName) == banks.end())
    {
        Screen::transactionFailed(-1, "This is not a Bank's card. Please enter a valid card.");
        Screen::newLine();
        return false;
    }
    if (!((banks[cardReader.bankName])->checkCardNumExist(cardReader.cardNumber)))
    {
        Screen::transactionFailed(-1, "Please enter a valid card.");
        Screen::newLine();
        return false;
    }
    Screen::bankName(cardReader.bankName);
    return true;
}

void Atm::readAndVerifyPin()
{
    std::string pin;
    for (int i= 0; i<3; ++i)
    {
        Screen::enterPin();
        std::cin>>pin;
        // sending the pin to bank to verify through bank api
        if ((banks[cardReader.bankName])->verifyPin(pin,cardReader.cardNumber)) 
        {
            pinVerified = true;
            return; 
        }
        else Screen::errorPin();
    }
    if (!pinVerified) (banks[cardReader.bankName])->verifyPin(pin,cardReader.cardNumber);
}

void Atm::selectAccType(){
    char input = '0';
    if (!pinVerified) return;
    Screen::accSelection();
    while (1)
    {
        std::cin>>input;
        if (input  == '1')
        {
            if (cardReader.accType != savings) Screen::notRightAccount("checking", "savings");
            break;
        }
        else if (input  == '2')
        {
            if (cardReader.accType != checking) Screen::notRightAccount("savings", "checking");
            break;
        }
        else Screen::selectValidOption();
    }
}


void Atm::doTransaction(){
    char input;
    int amount;
    Screen::welcome();
    
    readCard();
    if (!verifyCard()) return;
    if (cardReader.cardStatus != active)
    {
        Screen::cardStatus(cardReader.cardStatus);
        return;
    } 
    
    readAndVerifyPin();
    if (!pinVerified) return;

    selectAccType();

    while (1)
    {
        Screen::transactionOptions();
        std::cin>>input;
        if (input == '1') 
        {
            getBalance();
            break;
        }
        else if (input == '2') 
        {
            Screen::deposit();
            std::cin>>amount;
            depositMoney(amount);
            break;
        }
        else if (input == '3') 
        {
            Screen::withdraw();
            std::cin>>amount;
            withdrawMoney(amount);
            break;
        }
        else if (input == '4') 
        {
            cardReader.reset();
            break;
        }
        else Screen::selectValidOption();
    }
    pinVerified = false;
    cardReader.reset();
}

Atm::~Atm(){
    delete cashBin;
}
