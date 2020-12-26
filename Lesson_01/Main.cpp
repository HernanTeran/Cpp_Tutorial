#include <iostream>
#include <string>
#include "Account.h"

std::string getEmail();
std::string getPassword();
int getDay();
int getMonth();
int getYear();

int main()
{
    std::string email, password;

    email = getEmail();
    password = getPassword();

    int day, month, year;

    std::cout << "Enter your date of birth\n";

    day = getDay();
    month = getMonth();
    year = getYear();

    Account account(email, password, day, month, year);

    if (account.isAccountCreated())
    {
        std::cout << "Welcome to RuneScape!\n";
    }

    return 0;
}

std::string getEmail()
{
    std::cout << "Enter your email: ";

    std::string email;
    getline(std::cin, email);

    std::cout << "\n\n";

    return email;
}

std::string getPassword()
{
    std::cout
    << "Create a password\n"
    << "Password must have at least 1 uppercase letter.\n"
    << "Password must have at least 1 digit.\n"
    << "Password must not contain any special characters.\n"
    << "> ";

    std::string password;
    getline(std::cin, password);

    std::cout << "\n\n";

    return password;
}

int getDay()
{
    int day;

    std::cin >> day;

    return day;
}

int getMonth()
{
    int month;

    std::cin >> month;

    return month;
}

int getYear()
{
    int year;

    std::cin >> year;

    return year;
}
