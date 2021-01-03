#ifndef CPP_PRACTICE_MENU_H
#define CPP_PRACTICE_MENU_H
#include "Accounts.h"
#include <vector>
#include <string>

/*
 * @Menu
 *
 * This class is an abstract base class that
 * is to be inherited by a MainMenu class,
 * a LoginMenu class, and BillingMenu class.
 *
 * Its invariant is established by validating the login.
 * If accounts is empty or there is no account match
 * then an exception is thrown.
 */
class Menu
{
private:
    std::vector<Accounts> accounts;

public:
    Menu();

    explicit Menu(std::vector<Accounts> accounts);

    /*
     * @InvalidLogin
     *
     * This is the exception class.
     */
    class InvalidLogin{};

    /*
     * @getLoginInfo
     *
     * This is a template used
     * to avoid repetitive code from reading login info.
     */
    template <class T> std::string getLoginInfo();

    /*
     * @validateLogin
     *
     * This function performs the validation of a login.
     * If successful then the user will have access to their
     * account. Otherwise they will be denied access and
     * remain in the login menu.
     */
    bool validateLogin(std::vector<Accounts>&);

    /*
     * @displayMenu
     *
     * This is the function that makes this class abstract.
     * It is meant to be overridden because each menu
     * has a different display that come with different
     * options/functions.
     */
    virtual void displayMenu() = 0;

};

#endif //CPP_PRACTICE_MENU_H
