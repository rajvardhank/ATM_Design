##Flow:

1) welcome
2) insert card
3) verify card
4) enter pin
5) verify pin
6) give option to deposit/withdraw/see balance
7) do the transaction
8) return to main atm screen

##To do:
1) Documentation
3) debug code
4) test

##Tests:

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