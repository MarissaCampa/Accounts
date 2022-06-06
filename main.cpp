#include "Account_Manager.h"
#include <iostream>

int main(int, char**) 
{
    std::string sel = "x";
    Account_Manager mn;

    do 
    {
        mn.showMenu();
        flushInput(std::cin);
        std::getline(std::cin, sel);

        if (sel == "a" || sel == "A") 
        {
            // Open a new account
            mn.openNewAccount();
        }
        else if (sel == "b" || sel == "B") 
        {
            // Display all accounts
            mn.displayAllAccounts();
        }
        else if (sel == "c" || sel == "C") 
        {
            // Deposit to an account
            mn.depositToAccount();
        }
        else if (sel == "d" || sel == "D") 
        {
            // Withdraw from an account
            mn.withdrawFromAccount();
        }
        else if (sel == "x" || sel == "X") 
        {
            // Exit the program
            break;
        }
        else 
        {
            // Invalid option
            display_msg(Msg::ERROR, "Invalid");
        }
    } 
    while (sel != "x" && sel != "X");

    std::cout << std::endl;
    return 0;
}
