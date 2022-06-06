/**
 * @file Account_Manager.h
 * @author Marissa Campa (marissag.campa@gmail.com)
 * @brief Header file for the Account_Manager class
 * @copyright Copyright (c) 2022
 * 
 * This class can be instanciated and used as an interface
 * in the main function
 * 
 */
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
#include <algorithm>
#include <iomanip>

class Account_Manager {
private:
    // Class member is a vector of unique pointers of type
    // base class Account.
    // It is used to store pointers to classes that inherit from 
    // the Account class.
    // And it is used to facilitate polymorphic calls to methods of 
    // the classes that inherit from the Account class
    std::vector<std::unique_ptr<Account>> accounts;

protected:
    // Helper functions
    bool isDigit(const std::string &str);
    bool promptToOpenNewAccount(AccountTypes accountType);
    double getAmountFromUser();
    int getIndexFromUser();
    double promptToGetAmountForAccountAction(Action action);
    int promptToGetAccountIndex();
    void displayAddingNewAccountMessage(AccountTypes accountType);
    void printAccountsTableTitle();
    void printAccountsTableMembers(int index);
    void printAccountsTableDivider(bool bottom);

public:
    // Helper functions that can be  
    // called from the main function()
    void showMenu();
    bool openNewAccount();
    bool depositToAccount();
    bool withdrawFromAccount();
    void displayAllAccounts();
};


#endif