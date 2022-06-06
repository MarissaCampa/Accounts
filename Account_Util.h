/**
 * @file Account_Util.h
 * @author Marissa Campa (marissag.campa@gmail.com)
 * @brief Helper file that contains variables and functions useful
 *        to the Account_Manager and Account classes, and the main function
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef ACCOUNT_UTIL_H
#define ACCOUNT_UTIL_H

#include "Account.h"
#include <iostream>
#include <memory>
#include <vector>

// Classification of an account or account-derived object
enum class AccountTypes { REGULAR, SAVINGS, CHECKING, TRUST };

// Classification of the messages to display
enum class Msg { INFO, ERROR, USER };

// Classification of an action to perform on an account object
enum class Action { DEPOSIT, WITHDRAW };

/**
 * @brief Displays a message to the user according to the
 *          message classification dictated by the parameter m
 * 
 * @param m Classification of the message to display 
 * @param text Message to display to the user
 * @param add_jump If true, the function adds a line end character 
 *                  after the message
 */
static void display_msg(Msg m, std::string text, bool add_jump = true) {
    std::cout << ' ';
    if (m == Msg::INFO)
        std::cout << "[INFO] ";
    else if (m == Msg::ERROR)
        std::cout << "[ERROR] ";
    else if (m == Msg::USER)
        std::cout << "[USER] ";
    std::cout << text;
    if (add_jump)
        std::cout << '\n';
}

static void flushInput(std::istream &is) {
    is.clear();
    is.sync();
}




#endif  // _ACCOUNT_UTIL_H_