/**
 * @file Savings_Account.cpp
 * @author Marissa Campa (marissag.campa@gmail.com)
 * @brief Implementation file for the Savings_Account class
 * @date 2022-06-06
 * @copyright Copyright (c) 2022
 * 
 */
#include "Savings_Account.h"

/**
 * @brief Default Two-arg Constructor
 * 
 * Construct a new Savings_Account:: Savings_Account object
 * Utilizes the Account constructor to initialize inherited
 * member variables m_Name and m_Balance. It also initializes
 * class-specific m_InterestRate and m_Type.
 * 
 * @param name Name of the account
 * @param balance Initial balance of the account
 */
Savings_Account::Savings_Account(std::string name, double balance, double interest_rate) 
    : Account(name, balance), m_InterestRate(interest_rate), m_Type(AccountTypes::SAVINGS) {
}

/**
 * @brief Copy Constructor. 
 * 
 * Construct new Savings_Account:: Savings_Account object as a copy 
 * from a Savings_Account source object
 * 
 * @param src Source object
 */
Savings_Account::Savings_Account(const Savings_Account& src) 
    : Account(src.m_Name, src.m_Balance), m_InterestRate(src.m_InterestRate) {
}

/**
 * @brief Deposits an amount to the account balance
 * 
 * Overridden function inherited from the Account class.
 * The Savings Account adds an amount according to the m_InterestRate,
 * then it calls Account::deposit() method with the new amount
 * 
 * @param amount Amount to deposit to the account
 * @return true If the deposit is successful
 * @return false If the amount is not successful
 */
bool Savings_Account::deposit(double amount) {
    amount += (amount * m_InterestRate);
    return Account::deposit(amount);
}

/**
 * @brief Helper function that inserts the name and balance
 *      of the account to the output stream object parameter
 * 
 * Overridden function inherited from the I_Printable class
 * 
 * @param os Output stream object by reference
 */
void Savings_Account::print(std::ostream &os) const {
    os << "Savings Account: " << m_Name << ",  Balance: " << m_Balance;
}
