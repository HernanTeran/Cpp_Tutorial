#include "Menu.h"
#include <iostream>
#include <utility>

Menu::Menu() = default;

Menu::Menu(std::vector<Accounts> accounts) : accounts(std::move(accounts))
{
    bool validLogin = validateLogin(accounts);

    if (!validLogin)
    {
        throw InvalidLogin();
    }
}

template <class T>
std::string Menu::getLoginInfo()
{
    std::string info{};
    getline(std::cin, info);

    return info;
}

bool Menu::validateLogin(std::vector<Accounts> &account)
{
    if (account.empty())
    {
        throw InvalidLogin();
    }

    std::cout
    << "Log in\n"
    << "------\n"
    << "Email: ";

    std::string tempEmail = getLoginInfo<std::string>();

    std::cout << "Password: ";

    std::string tempPass = getLoginInfo<std::string>();

    bool successful = false;

    for (const Accounts &acc : accounts)
    {
        successful = tempEmail == acc.getEmail() && tempPass == acc.getPassword();

        if (successful)
        {
            std::cout << "\nWelcome Back: " << acc.getDisplayName() << "\n\n";
        }
        else
        {
            throw InvalidLogin();
        }
    }

    return successful;
}