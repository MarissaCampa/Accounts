/**
 * @file Trust_Account.cpp
 * @author Marissa Campa (marissag.campa@gmail.com)
 * @brief Implementation file for the Trust_Account class
 * @date 2022-06-06
 * @copyright Copyright (c) 2022
 * 
 */
#include "Trust_Account.h"

/**
 * @brief Default Two-arg Constructor
 * 
 * Construct a new Trust_Account:: Trust_Account object
 * Utilizes the Savings_Account constructor to initialize inherited
 * member variables m_Name, m_Balance and m_InterestRate. It also initializes
 * class-specific m_TotalMovements and m_Type.
 * 
 * @param name Name of the account
 * @param balance Initial balance of the account
 * @param interest_rate Interest rate for deposits to the account
 */
Trust_Account::Trust_Account(std::string name, double balance, double interest_rate) 
    : Savings_Account(name, balance, interest_rate), m_TotalMovements(0), m_Type(AccountTypes::TRUST) {
}

/**
 * @brief Copy Constructor. 
 * 
 * Construct new Trust_Account:: Trust_Account object as a copy 
 * from a Trust_Account source object
 * 
 * @param src Source object
 */
Trust_Account::Trust_Account(const Trust_Account& src) 
    : Savings_Account(src.m_Name, src.m_Balance, src.m_InterestRate), m_TotalMovements(src.m_TotalMovements) {
}

/**
 * @brief Deposits an amount to the account balance
 * 
 * Overridden function inherited from the Savings_Account class.
 * The Trust Account has a limit of movements that can be done in a year
 * (it currently does not take into consideration time periods, only for demonstration)
 * The Trust Account also add a bonus amount if the amount to deposit is greater
 * than the minimum amount for the bonus.
 * Possible movements for the account are deposit and withdraw.
 * 
 * @param amount Amount to deposit to the account
 * @return true If the current movements of the account is less than the total
 *          movements allowed, and if the Savings_Account::deposit() is successful
 * @return false If the current movements of the account is greater than the total
 *          movements allowed
 */
bool Trust_Account::deposit(double amount) {
    if (m_TotalMovements < c_TotalMovementsAllowed) {
        m_TotalMovements++;
        amount += amount >= c_MinumumAmountForBonus ? c_Bonus : 0; 
        return Savings_Account::deposit(amount);
    }
    display_msg(Msg::INFO, "Limit of movements per year has been reached");
    return false;
}

/**
 * @brief Withdraws an amount from the account balance
 * 
 * Overridden function inherited from the Savings_Account class.
 * The Trust Account has a limit of movements that can be done in a year
 * (it currently does not take into consideration time periods, only for demonstration)
 * Possible movements for the account are deposit and withdraw.
 * 
 * @param amount Amount to withdraw from the account
 * @return true If the current movements of the account is less than the total
 *          movements allowed, and if the Savings_Account::withdraw() is successful
 * @return false If the current movements of the account is greater than the total
 *          movements allowed
 */
bool Trust_Account::withdraw(double amount) {
    if (m_TotalMovements < c_TotalMovementsAllowed) {
        m_TotalMovements++;
        return Savings_Account::withdraw(amount);
    }
    display_msg(Msg::INFO, "Limit of movements per year has been reached");
    return false;
}

/**
 * @brief Helper function that inserts the name, balance and 
 *      total movements of the account to the output stream
 *      object parameter
 * 
 * Overridden function inherited from the I_Printable class
 * 
 * @param os Output stream object by reference
 */
void Trust_Account::print(std::ostream &os) const {
    os << "Trust Account: " << m_Name << ",  Balance: " << m_Balance << ",  Total movements: " << m_TotalMovements;
}
