#include "header_files/CashBin.h"


CashBin::CashBin(int amount) : amountInAtm(amount){}

bool CashBin::dispenseCash(int amount){
    if (amount <= amountInAtm) 
    {
        amountInAtm -= amount;
        return true;
    }
    return false;
}

void CashBin::putCash(int amount){
    amountInAtm += amount;
}