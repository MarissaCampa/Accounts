/**
 * @file Account.cpp
 * @author Marissa Campa (marissag.campa@gmail.com)
 * @brief Implementation file for the Account class
 * @date 2022-06-06
 * @copyright Copyright (c) 2022
 * 
 */
#include "Account.h"

/**
 * @brief Default Two-arg Constructor
 * 
 * Construct a new Account:: Account object
 * Initializes m_Name, m_Balance and m_Type.
 * 
 * @param name Name of the account
 * @param balance Initial balance of the account
 */
Account::Account(std::string name, int balance) 
    : m_Name(name), m_Balance(balance), m_Type(AccountTypes::REGULAR) {
}

/**
 * @brief Copy Constructor. 
 * 
 * Construct new Account:: Account object as a copy from
 * an Account source object
 * 
 * @param src Source object
 */
Account::Account(const Account& src)
    : Account(src.m_Name, src.m_Balance) {
}

/**
 * @brief Deposits an amount to the account balance
 * 
 * @param amount Amount to deposit to the account
 * @return true If the deposit is successful
 * @return false If the amount is less than or equal to 0
 */
bool Account::deposit(double amount) {
    if (amount > 0) {
        m_Balance += amount;
        return true;
    }
    return false;
}

/**
 * @brief Withdraws an amount from the account balance
 * 
 * @param amount Amount to withdraw from the account
 * @return true If the amount is greater than or equal to the balance,
 *              and if the amount is greater than 0
 * @return false If the amount to withdraw is less than the balance
 */
bool Account::withdraw(double amount) {
    if (m_Balance >= amount && amount > 0) {
        m_Balance -= amount;
        return true;
    }
    return false;
}

/**
 * @brief Helper function that inserts the name and balance
 *      of the account to the output stream object parameter
 * 
 * Overridden function inherited from the I_Printable class
 * 
 * @param os Output stream object by reference
 */
void Account::print(std::ostream &os) const {
    os << "Account: " << m_Name << ",  Balance: " << m_Balance;
}

