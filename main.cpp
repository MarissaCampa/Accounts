#include "Account_Manager.h"
#include <iostream>

const int BUFFER_SIZE = 50;

int main(int, char**) 
{
    std::string sel = "x";
    Account_Manager mn;
    std::cin.clear();
    std::cin.sync();

    do 
    {
        mn.showMenu();
        std::getline(std::cin, sel);

        if (sel == "a" || sel == "A") 
        {
            // Open a new account
            if (mn.openNewAccount())
                display_msg(msg::INFO, "Created successfully");
            else 
                display_msg(msg::ERROR, "Not created");
        }
        else if (sel == "b" || sel == "B") 
        {
            // Display all accounts
            mn.displayAllAccounts();
        }
        else if (sel == "c" || sel == "C") 
        {
            // Deposit to all accounts
            std::cout << "Enter the amount to deposit to all accounts: ";
            double amount = mn.getAmountFromUser();
            if (amount > -1) 
                mn.depositToAll(amount);
        }
        else if (sel == "d" || sel == "D") 
        {
            // Withdraw from all accounts
            std::cout << "Enter the amount to withdraw from all accounts: ";
            double amount = mn.getAmountFromUser();
            if (amount > -1) 
                mn.withdrawFromAll(amount);
        }
        else if (sel == "x" || sel == "X") 
        {
            break;
        }
        else 
        {
            display_msg(msg::ERROR, "Invalid");
        }
    } 
    while (sel != "x" && sel != "X");

    std::cout << std::endl;
    return 0;
}
