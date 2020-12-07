#include "header_files/Atm.h"
#include "header_files/Bankobjs.h"
#include "header_files/Screen.h"


std::unordered_map<std::string, Bank*> banks;

int main(){

    createbanks();
    createAccounts();
    Atm atm;
    char input = '1';

    while (input != '0')
    {
        atm.doTransaction();
        Screen::exitAtm();
        std::cin>>input;
        Screen::newLine();
    }

    for (auto i: banks) delete i.second;

    return 0;
}