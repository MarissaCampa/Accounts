/**
 * @file Checking_Account.h
 * @author Marissa Campa (marissag.campa@gmail.com)
 * @brief Header file for the Checking_Account class
 * @date 2022-06-06
 * @copyright Copyright (c) 2022
 * 
 * The Checking_Account class inherits from the Account class 
 * 
 */
#ifndef CHECKING_ACCOUNT_H
#define CHECKING_ACCOUNT_H

#include "Account.h"
#include <iostream>
#include <string>

class Checking_Account : public Account 
{
private:
    // Helper variables for the default arguments of the constructor
    static constexpr const char *c_DefaultName = "Checking Account";
    static constexpr const int c_DefaultBalance = 0.0;
    static constexpr const double c_WithdrawFee = 1.5;

    // Type of account, specific to this class
    AccountTypes m_Type;

public:
    // Default two-arg constructor
    Checking_Account(std::string name = c_DefaultName, double balance = c_DefaultBalance);

    // Copy constructor
    Checking_Account(const Checking_Account& src);

    // Virtual default constructor
    virtual ~Checking_Account() = default;

    // Overridden methods from the Account class
    virtual AccountTypes getType() const override { return m_Type; }
    virtual bool withdraw(double amount) override;
    virtual void print(std::ostream &os) const override;
};


#endif // _CHECKING_ACCOUNT_H_