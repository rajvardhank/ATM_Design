#pragma once
#include "unordered_map"
#include "Bank.h"
#include <string>


std::unordered_map<std::string, Bank*> banks = {{"bankA",new Bank("bankA")},
                                                {"bankB",new Bank("bankB")},
                                                {"bankC",new Bank("bankC")}
};

void createAccounts();