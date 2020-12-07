#pragma once
#include <unordered_map>
#include "Bank.h"

/* A Global map which stores the instantiated objects of the bank class.
This represents the banks in real worls. That is the banks are situated in one place
and they only provide their API to the ATMS to operate. */
extern std::unordered_map<std::string, Bank*> banks;

// Modify these functions to create your own banks and accounts
void createbanks();
void createAccounts(); // create accounts in the created banks.