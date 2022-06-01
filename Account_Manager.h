#ifndef ACCOUNT_MANAGER_H
#define ACCOUNT_MANAGER_H

#include "Account.h"
#include "Account_Util.h"
#include "Account_Manager.h"
#include "Checking_Account.h"
#include "Savings_Account.h"
#include "Trust_Account.h"
#include <iostream>
#include <fstream>
#include <string>
#include <memory>
#include <vector>
#include <limits>

class Account_Manager {
private:
    std::vector<std::unique_ptr<Account>> accounts;
public:
    void showMenu();
    bool openNewAccount();
    void depositToAll(double amount);
    void withdrawFromAll(double amount);
    double getAmountFromUser();
    void displayAllAccounts();
};


#endif