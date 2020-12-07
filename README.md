# Atm_Design
ATM design in C++ using OOP

## Running the program:
### Method 1:
Download:
1. "atm.exe"
2. "cards" folder 
3. "libgcc_s_dw2-1.dll"
4. "libstdc++-6.dll"
5. Delete the .txt files in cards folder
6. Run the .exe directly by double clicking on it.

### Method 2:
1. Clone/download the whole directory.
2. Run these 2 commands in the terminal at the that directory.
    * g++ -c *.cpp
    * g++ *.o -o atm
3. Delete the .txt files in cards folder
4. Run the .exe directly by double clicking on it.

## How to use the app:
1. Delete all the existing atm cards (*.txt files) in the cards folder.
2. Run the app, new cards (**card#**_**cardPin**.txt) will be generated in the cards folder.
3. Select the card you want and insert it. (type **card#**_**cardPin**)
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
3. __class Bank__: The Bank class is used create different banks, they store the cusstomer accounts (__class Account objects__). This class provides an API to the ATM. There is a status option for the card and account as "active", "blocked", "suspended". Although the code never sets the status of the card or account as "suspended", its given as an option to the bank as admin power to suspend an account. If the status is changed manually, no transaction will be allowed.
4. __class CardReader__: This class is used by the Atm, it reads the users card and stores its info. 
5. __class CashBin__: This class stores the cash for the Atm, for simplicity the atm is instantiated with $10000.
4. __class Atm__: This class is used to implement the atm, it does the transaction using all the above classes. 
7. __class Screen__: This class is used to print anyhting to the screen. 

## Current Account and Card Details Created for you using "Bankobjs.h":
__Note:__ The generated cards will be as listed most of the times, but since some details of the card are generated randomly, these listed cards might not work, in that case please check the cards folder for card details. 


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

4. Account: 12348
    * Bank: bankC
    * Account Type: Checking Account
    * Balance: $100.00
    * ATM Withdrawal Limit: $1000.00
    * Card Details:
        * Card #: 12346
        * Expiry Date: 4/2/2023
        * CVV = 161
        * PIN = 1491


## Testing:

1. Testing if the atm can recognise if its not a bank card.
    * Option 1 - Enter a random number when it asks you to insert card.
    * Option 2 - After running the .exe, change the card number inside the .txt file generated in cards folder, while keeping the file name as it is.
    * Expected behavior: will print an error message. 
2. Input wrong pin for more than 3 times. 
    * Expected behaviour: will block the card. Can check the card status by manually opening the cards respective .txt file.
    * Without shutting the app, do another transaction with the same card.
    * Expected Behaviour: should not allow transaction.
3.  Testing if card/account is blocked/suspended:
    * After running the .exe, manully change the status of card from "active" to "blocked" or "suspended" in its .txt file. Use that card.
    * Expected Behaviour: should not allow transaction.
4. Selecting wrong option number when provided with options:
    * Expected behaviour: Will print an error telling to select a valid option.
5. Try normal transactions: check balance, deposit money, withdraw money with different cards and individually (ie. close the app after each transaction and open it again):
    * Expected behaviour: should work smoothly.
6. Try normal transactions: check balance, deposit money, withdraw money with different cards without closing the app.
    * Expected behaviour:
        * should change the amount of cash in atm cash bin, over the period of transactions.
        * should change the balance of the account over multiple transaction.
        * if an account is blocked, no further transactions must be allowed, unless you manually change the status. 
7. Withdraw money from savings account:
    * Expected Behaviour: should charge a transaction fee.
8. Withdraw money from checking account with not enough balance:
    * Use card: "12348_1491".
    * withdraw $500.00
    * Expected behavior: should print error message
9. Withdraw money from savings account with just enough balance for the amount but not for the fee:
    * Use card: "12345_9500".
    * withdraw $1000.00
    * Expected behavior: should print error message
10. Withdraw money more than account atm withdrawal limit ($1000):
    * Use card: "12346_3358"
    * withdraw $2000.0
    * Expected behavior: should print error message
11. Testing ATM out of money scenario:
    * Use card: "12347_2145".
    * withdraw $1000.00
    * Expected behavior: should print error message


# Thank You!
