#ifndef _ACCOUNT_MANAGER_H_
#define _ACCOUNT_MANAGER_H_

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

class Account_Manager {
private:
    std::vector<std::unique_ptr<Account>> accounts;
public:
    void showMenu();
    bool openNewAccount();
};


#endif