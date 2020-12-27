#include <iostream>
#include <string>
#include "Account.h"

/*
 * annotate program
 * add exception classes for account creation - check password,DOB
 * set display name
 * menu to display created account with ability to change password/display name
 */

std::string getEmail();
std::string createPassword();
std::string getDOB();
Account createAccount();

int main()
{
    Account account = createAccount();

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

    //flag
    bool accountCreated = true;

    do
    {
        try
        {
            Account account(email, newPassword, dateOfBirth);

            accountCreated = true;
        }
        catch (Account::EmailError &emailError)
        {
            std::cerr
            << "Email error: " << emailError.getErrorEmail() << '\n'
            << "Try again: ";

            getline(std::cin, email);
        }

    } while (!accountCreated);

    return account;
}
