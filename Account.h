/**
 * @file Account.h
 * @author Marissa Campa (marissag.campa@gmail.com)
 * @brief Header file for the Account class
 * @copyright Copyright (c) 2022
 * 
 * The Account class inherits from the I_Printable class 
 */
#ifndef ACCOUNT_H
#define ACCOUNT_H

#include "I_Printable.h"
#include "Account_Util.h"
#include <iostream>
#include <string>

class Account : public I_Printable
{
protected:
    // Class members that can be inherited
    std::string m_Name;
    double m_Balance;

private:
    // Helper variables for the default arguments of the constructor
    static constexpr const char *c_DefaultName = "Default Account";
    static constexpr const int c_DefaultBalance = 0.0;

    // Type of account, specific to this class
    AccountTypes m_Type;

public:
    // Default two-arg constructor
    Account(std::string name = c_DefaultName, int balance = c_DefaultBalance);

    // Copy constructor
    Account(const Account& src);

    // Virtual default destructor
    virtual ~Account() = default;       

    // Getter methods declared as virtual for inheritance
    virtual std::string getName() const { return m_Name; }
    virtual double getBalance() const { return m_Balance; }
    virtual AccountTypes getType() const { return m_Type; }

    // Public methods declared as virtual for inheritance
    virtual bool deposit(double amount);
    virtual bool withdraw(double amount);

    // Overriden method from the I_Printable class
    virtual void print(std::ostream &os) const override;
};

#endif // ACCOUNT_H