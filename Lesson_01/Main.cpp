#include <iostream>
#include <string>
#include <vector>
#include "Account.h"

/*
 * annotate program
 * add exception for account display name
 * set display name
 * menu to display created account with ability to change password/display name
 */

std::string getEmail();
std::string createPassword();
std::string getDOB();
Account createAccount();

int main()
{
    std::vector<Account> accounts;

    try
    {
        Account account = createAccount();
        accounts.emplace_back(account);
    }
    catch (Account::InvalidAccount)
    {
        std::cerr << "Invalid account information entered.\n"
                  << "Try again.\n";
    }
    return 0;
}

std::string getEmail()
{
    std::cout << "Enter your email: ";

    std::string email;
    getline(std::cin, email);

    std::cout << '\n';

    return email;
}

std::string createPassword()
{
    std::cout
    << "Create a password\n"
    << "Password must have at least 1 uppercase letter.\n"
    << "Password must have at least 1 digit.\n"
    << "Password must not contain any special characters.\n"
    << "Password must be between 5 & 20 characters long.\n"
    << "> ";

    std::string password;
    getline(std::cin, password);

    std::cout << '\n';

    return password;
}

std::string getDOB()
{
    std::cout << "Enter your date of birth (DD/MM/YYYY): ";
    std::string dateOfBirth;
    getline(std::cin, dateOfBirth);

    std::cout << '\n';

    return dateOfBirth;
}

Account createAccount()
{
    //account variables
    const std::string email = getEmail(),
                      newPassword = createPassword(),
                      dateOfBirth = getDOB();

    Account account(email, newPassword, dateOfBirth);

    return account;
}
