/**
 * @file Savings_Account.h
 * @author Marissa Campa (marissag.campa@gmail.com)
 * @brief Header file for the Savings_Account class
 * @copyright Copyright (c) 2022
 * 
 * The Savings_Account class inherits from the Account class 
 */
#ifndef SAVINGS_ACCOUNT_H
#define SAVINGS_ACCOUNT_H

#include "Account.h"
#include <iostream>
#include <string>

class Savings_Account : public Account 
{
private:
    // Helper variables for the default arguments of the constructor
    static constexpr const char *c_DefaultName = "Savings Account";
    static constexpr const double c_DefaultBalance = 0.0;

    // Type of account, specific to this class
    AccountTypes m_Type;

protected:
    // Helper variable for the default arguments of the constructor
    static constexpr const double c_DefaultInterestRate = 0.03;

    // Class members that can be inherited
    double m_InterestRate;

public:
    // Default three-arg constructor
    Savings_Account(std::string name = c_DefaultName, double balance = c_DefaultBalance, double interest_rate = c_DefaultInterestRate);

    // Copy constructor
    Savings_Account(const Savings_Account& src);

    // Virtual default destructor
    virtual ~Savings_Account() = default;

    // Overriden methods from the Account class
    virtual AccountTypes getType() const override { return m_Type; }
    virtual bool deposit(double amount) override;

    // Overriden method from the I_Printable class
    virtual void print(std::ostream &os) const override;
};

#endif