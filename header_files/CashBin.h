#pragma once
#include <string>

class CashBin{
    
    private:
        int amountInAtm;
    
    public:
        CashBin(int amount);
        bool dispenseCash(int amount);
        void putCash(int amount);
};