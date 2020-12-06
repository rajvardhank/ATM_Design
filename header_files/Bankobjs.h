#pragma once
#include <unordered_map>
#include "Bank.h"


extern std::unordered_map<std::string, Bank*> banks;
void createbanks();
void createAccounts();