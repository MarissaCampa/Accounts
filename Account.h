#ifndef ACCOUNT_H
#define ACCOUNT_H

#include "I_Printable.h"
#include "Account_Util.h"
#include <iostream>
#include <string>

class Account : public I_Printable
{
private:
    static constexpr const char *def_name = "Default Account";
    static constexpr const int def_balance = 0.0;
protected:
    std::string name;
    double balance;
public:
    Account(std::string n = def_name, int a = def_balance);
    Account(const Account& src);
    virtual ~Account() = default;

    double getBalance() const { return balance; }

    virtual bool deposit(double amount);
    virtual bool withdraw(double amount);
    virtual void print(std::ostream &os) const override;
};

#endif