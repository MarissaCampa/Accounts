#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_

#include "I_Printable.h"
#include <iostream>
#include <string>

class Account : public I_Printable
{
private:
    static constexpr const char *def_name = "Default Account";
    static constexpr const int def_balance = 0.0;
protected:
    enum class msg { INFO, ERROR, USER };
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
    void display_msg(msg m, std::string text, bool add_jump = true);
};

#endif