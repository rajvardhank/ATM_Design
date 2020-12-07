# Atm_Design
ATM design in C++ using OOP

## Running the program:
You can either download the "atm.exe" and the cards folder and run the .exe directly.

Or else, clone/download the whole directory.
And run these 2 commands in the terminal at the that directory.

g++ -c *.cpp
g++ *.o -o atm.exe

And then run the atm.exe

## How to use the app:
1. Delete all the existing atm cards (*.txt files) in the cards folder.
2. Run the app, new cards (<card#>_<pin>.txt) will be generated in the cards folder.
3. Select the card you want and insert it. (type <card#>_<pin>)
4. Enter the pin.
5. Enter the account type.
6. Select the Transaction you want to do.
7. You can then exit the ATM or do another transaction.

## Flow of the Code:
1. All the statements are printed to the screen using the __"Screen class"__. 

2. Creating Banks, their accounts, and their Atm cards:
    * When you run the .exe, different banks are created and stored in a __global dictonary__ and can be accessed using their names.
    * If anyone wants to create banks with the names they want, they can do so by adding it in the __"Bankobjs.cpp"__ file. Please keep in mind you'll have to complie the code again.
    * Once the banks are created, you can then open a savings/checking ccount in the bank you want. Currently for simplicity some banks and accounts have been opened for you. To edit them, you can edit __"Bankobjs.cpp"__.
    * When the accounts are created, their atm cards are created automatically and stored in the __"cards"__ folder. 

3. You then enter the ATM (class __"Atm"__):
    * The Atm can never access the customers account. The Atm's method's send information to the respective Bank's API and the Bank does the work. 
    * Using the __"class CardReader"__, the atm will read and store the card info. 
    * Using its own private methods, it will send the information to the repective Banks API and verify the card and check if the card is valid and will also check if the card is blocked or suspended. (You'll get an error if you enter a wrong card)
    * Then it will ask for the pin, which will be verified by the bank. If the user enters wrong pin for 3 times, his card will get blocked and he wont be able to do any future transactions. (Note: if you close the app and run it again, new cards will be created and all of them will be active. But if you didn't close the app after first 3 failed attempts and do another transaction with the same card, you will get card blocked message.)
    * After that you will be asked you account type, you can enter any type, it will redirect you to the type your card is associated with.
    * After that you'll have to select the transaction options and using the Bank's API, all the transactions will be done.
    * While withdrawing money, the atm, using the Bank's API, will stop the transaction if the amount entered is more than your atm withdrawal limt or if the amount is more than the balance in your account. (For simplicty the atm withdrawal is set at $1000 for all the accounts.)
    * While doing the transactions, the Class object __"CashBin"__ inside the atm will be updated. If the atm dosen't have enough money while transaction, it will print an error.  

## Code Description:
The code has been explained in the header and source files using descriptive function and variable names and using comments wherever required, please check the __header_files__. This is a brief description of the classes used in the project. 

1. __class Card__: This class is used to generate new atm cards, they store the card info like, expiry date, cvv etcetera.
2. __class Account__: This stores the account info, customer info and atm card and provides the bank an API to modify the balance in the account. It has 2 subclasses __class SavingsAccount__ and __class CheckingAccount__.
3. __class Bank__: The Bank class is used create different banks, they store the cusstomer accounts (__class Account objects__). This class provides an API to the ATM. 
4. __class CardReader__: This class is used by the Atm, it reads the users card and stores its info. 
5. __class CashBin__: This class stores the cash for the Atm, for simplicity the atm is instantiated with $10000.
4. __class Atm__: This class is used to implement the atm, it does the transaction using all the above classes. 
7. __class Screen__: This class is used to print anyhting to the screen. 

## Current Account and Card Details Created for you using "Bankobjs.h":
1. Account: 12345
    * Bank: bankA
    * Account Type: Savings Account
    * Balance: $1000.00
    * ATM Withdrawal Fee: $5.00
    * ATM Withdrawal Limit: $1000.00
    * Card Details:
        * Card #: 12345
        * Expiry Date: 12/12/2023
        * CVV = 134
        * PIN = 9500

2. Account: 12346
    * Bank: bankA
    * Account Type: Checking Account
    * Balance: $500.00
    * ATM Withdrawal Limit: $1000.00
    * Card Details:
        * Card #: 12346
        * Expiry Date: 5/30/2023
        * CVV = 778
        * PIN = 3358

3. Account: 12347
    * Bank: bankB
    * Account Type: Savings Account
    * Balance: $12000.00
    * ATM Withdrawal Fee: $10000.00
    * ATM Withdrawal Limit: $1000.00
    * Card Details:
        * Card #: 12347
        * Expiry Date: 09/23/2023
        * CVV = 405
        * PIN = 2145


## Testing:

1)Insert card, put pin, check balance - succesful.
2)Insert card, put pin, deposit money - succesful.
3)Insert card, put pin, withdraw money - succesful.
4)Do the above tests individuly after exiting the atm and then do them together without exiting the ATM.
4)Insert card, wrong pin, then right pin, check balance/deposite money/withdraw money - succesfull.
5)Insert card, put pin, withdraw more than limit - unsuccesfull.
6)Insert card, put pin, withdraw more than account balance - unsuccesfull.
7)Insert card, put pin, withdraw from savings more than account balance including fees - unsuccesfull.
8)Insert card, wrong pin 3 times, card should be blocked, check txt file, try the card again
all future transactions should be blocked - unsuccesfull.
9) atm out of money