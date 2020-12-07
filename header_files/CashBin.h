#pragma once
#include <string>


// This is the cash bin of the ATM which stores, and dispenses cash for the ATM. 
class CashBin{
    
    private:
        int amountInAtm;
    
    public:
        CashBin(int amount);
        bool dispenseCash(int amount);
        void putCash(int amount);
};