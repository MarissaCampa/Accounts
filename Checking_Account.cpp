/**
 * @file Checking_Account.cpp
 * @author Marissa Campa (marissag.campa@gmail.com)
 * @brief Implementation file for the Checking_Account class
 * @date 2022-06-06
 * @copyright Copyright (c) 2022
 * 
 */
#include "Checking_Account.h"

/**
 * @brief Default Two-arg Constructor
 * 
 * Construct a new Checking_Account:: Checking_Account object
 * Utilizes the Account constructor to initialize inherited
 * member variables m_Name and m_Balance. It also initializes
 * class-specific m_Type.
 * 
 * @param name Name of the account
 * @param balance Initial balance of the account
 */
Checking_Account::Checking_Account(std::string name, double balance) 
    : Account(name, balance), m_Type(AccountTypes::CHECKING) {
}

/**
 * @brief Copy Constructor. 
 * 
 * Construct new Checking_Account:: Checking_Account object as a copy 
 * from a Checking_Account source object
 * 
 * @param src Source object
 */
Checking_Account::Checking_Account(const Checking_Account& src) 
    : Account(src.m_Name, src.m_Balance) {
}

/**
 * @brief Withdraws an amount from the account balance
 * 
 * Overridden function inherited from the Account class.
 * There is a fee for withdrawing from a Checking Account.
 * If the amount to withdraw is greater than the withdraw fee,
 * it call the base class Account::withdraw() method with
 * the amount plus the withdraw fee
 * 
 * @param amount Amount to withdraw from the account
 * @return true If the amount is greater than or equal to the withdraw fee
 * @return false If the amount to withdraw is less than the withdraw fee
 */
bool Checking_Account::withdraw(double amount) {
    if (amount > c_WithdrawFee)
        return Account::withdraw(amount + c_WithdrawFee);
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
void Checking_Account::print(std::ostream &os) const {
    os << "Checking Account: " << m_Name << ",  Balance: " << m_Balance;
}

