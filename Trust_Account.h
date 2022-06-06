/**
 * @file Trust_Account.h
 * @author Marissa Campa (marissag.campa@gmail.com)
 * @brief Header file for the Trust_Account class
 * @copyright Copyright (c) 2022
 * 
 * The Trust_Account class inherits from the Account class 
 */
#ifndef TRUST_ACCOUNT_H
#define TRUST_ACCOUNT_H

#include "Savings_Account.h"
#include <iostream>
#include <string>

class Trust_Account : public Savings_Account 
{
private:
    // Helper variables for the default arguments of the constructor
    static constexpr const char *c_DefaultName = "Trust Account";
    static constexpr const int c_DefaultBalance = 0.0;
    static constexpr const double c_MinumumAmountForBonus = 5000;
    static constexpr const double c_Bonus = 50.0;
    static constexpr const int c_TotalMovementsAllowed = 3;

    // Type of account, specific to this class
    AccountTypes m_Type;

protected:
    // Class members that can be inherited
    unsigned int m_TotalMovements;

public:
    // Default three-arg constructor
    Trust_Account(std::string name = c_DefaultName, double balance = c_DefaultBalance, double interest_rate = c_DefaultInterestRate);

    // Copy constructor
    Trust_Account(const Trust_Account& src);

    // Virtual default constructor
    virtual ~Trust_Account() = default;

    // Overriden methods from the Savings_Account class
    virtual AccountTypes getType() const override { return m_Type; }
    virtual bool deposit(double amount) override;
    virtual bool withdraw(double amount) override;

    // Overriden method from the I_Printable class
    virtual void print(std::ostream &os) const override;
};

#endif