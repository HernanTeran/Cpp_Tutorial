#include <iostream>
#include <string>
#include <vector>
#include "Account.h"

/* create an account */
std::string getEmail();
std::string createPassword();
std::string getDOB();
Account createAccount(const std::vector<Account>&);
std::string selectDisplayName();

/* check for taken emails/display names */
std::string validateEmail(const std::vector<Account>&, std::string&);
std::string validateDisplayName(const std::vector<Account>&, std::string&);

/* menus */
void mainMenu();
bool validLogin(const std::vector<Account>&);
void loginMenu(std::vector<Account>&);
void gameMenu();
std::size_t getChoice();
void logout(bool&, std::size_t&);

/* change display name or password */
void changePassword(std::vector<Account> &);
void changeDisplayName(std::vector<Account>&);

/*
 * @main()
 *
 * The purpose of this program is to simulate
 * the process of creating and managing a RuneScape account.
 *
 * This program is meant for only one account at this point.
 */

int main()
{
    std::vector<Account> accounts;

    std::size_t choice_menu1 = 0;

    do
    {
        mainMenu();
        choice_menu1 = getChoice();
        std::cin.ignore();

        switch (choice_menu1)
        {
            case 1:
                loginMenu(accounts);
                break;
            case 2:
                try
                {
                    Account account = createAccount(accounts);

                    /* account created */
                    accounts.emplace_back(account);
                }
                catch (Account::InvalidAccount)
                {
                    std::cerr << "Invalid account information entered!\n"
                              << "Try again.\n";
                }
                break;
            case 3:
                std::cout << "Goodbye!\n";
                break;
            default:
                std::cerr << "Invalid choice. Try again.\n";
        }

    } while (choice_menu1 != 3);

    return 0;
}

/* create an account */

/*
 * @getEmail()
 *
 * This function returns a string that holds an email
 * from a new user.
 *
 * The value is validated by an exception class
 * when attempting to create a new Account object.
 */
std::string getEmail()
{
    std::cout << "Enter your email: ";

    std::string email{};
    getline(std::cin, email);

    std::cout << '\n';

    return email;
}

/*
 * @createPassword()
 *
 * This function returns a string that holds
 * a password from a new user.
 *
 * The value is validated by an exception class
 * when attempting to create a new Account object.
 */

std::string createPassword()
{
    std::cout
    << "Create a password\n"
    << "Password must have at least 1 uppercase letter.\n"
    << "Password must have at least 1 digit.\n"
    << "Password must not contain any special characters.\n"
    << "Password must be between 5 & 20 characters long.\n"
    << "> ";

    std::string password{};
    getline(std::cin, password);

    std::cout << '\n';

    return password;
}

/*
 * @getDOB()
 *
 * This function returns a string that holds
 * the date of birth of a new user.
 *
 * The value is validated by an exception class
 * when attempting to create a new Account object.
 */

std::string getDOB()
{
    std::cout << "Enter your date of birth (DD/MM/YYYY): ";
    std::string dateOfBirth{};
    getline(std::cin, dateOfBirth);

    std::cout << '\n';

    return dateOfBirth;
}

/*
 * @createAccount()
 *
 * This function creates an Account object by calling
 * other functions to fill its constructor.
 *
 * It is validated by an exception class.
 */


Account createAccount(const std::vector<Account> &accounts)
{
    /* account variables */
    std::string email = getEmail();
    email = validateEmail(accounts, email);

    const std::string newPassword = createPassword(),
                      dateOfBirth = getDOB();

    Account account(email, newPassword, dateOfBirth);

    /* set display name */
    std::string displayName = selectDisplayName();
    displayName = validateDisplayName(accounts, displayName);
    account.setDisplayName(displayName);

    std::cout << "Display name set!\n\n";

    return account;
}

/*
 * @selectDisplayName()
 *
 * This function returns a string that holds
 * the display name of a new account after
 * an Account object has been created.
 *
 * It is validated by a function
 * that throws an exception from
 * an exception class.
 */

std::string selectDisplayName()
{
    std::cout << "\nChoose display name: ";
    std::string name{};
    getline(std::cin, name);

    std::cout << '\n';

    return name;
}

/*
 * @validateEmail() & @validateDisplayName()
 *
 * These functions validate a string that holds an email/display name
 * after an Account object has been created.
 *
 * It throws an exception if invalid.
 */

std::string validateEmail(const std::vector<Account> &accounts, std::string &email)
{
    if (accounts.empty())
    {
        return email;
    }
    else
    {
        for (const Account &account : accounts)
        {
            if (account.getEmail() == email)
            {
                throw Account::InvalidAccount();
            }
        }
    }
    return email;
}

std::string validateDisplayName(const std::vector<Account>& accounts, std::string &name)
{
    if (accounts.empty())
    {
        return name;
    }
    else
    {
        for (const Account &account : accounts)
        {
            if (account.getDisplayName() == name)
            {
                throw Account::InvalidAccount();
            }
        }
    }
    return name;
}

/* menus */

/*
 * @mainMenu()
 *
 * This function prints a menu that
 * is meant for new/existing users.
 */

void mainMenu()
{
    std::cout
    << "Welcome to RuneScape!\n"
    << "---------------------\n"
    << "1. Log in\n"
    << "2. Create an account\n"
    << "3. Exit\n\n";
}

/*
 * @validLogin()
 *
 * This function validates a login and is
 * meant for existing users.
 */

bool validLogin(const std::vector<Account> &accounts)
{
    if (accounts.empty())
    {
        std::cerr << "\nCreate an account first!\n\n";
        return false;
    }

    std::cout
    << "Log in\n"
    << "------\n"
    << "Email: ";

    std::string tempEmail{};
    getline(std::cin, tempEmail);

    std::cout << "Password: ";

    std::string tempPass{};
    getline(std::cin, tempPass);

    bool successful = false;

    for (const Account &account : accounts)
    {
        successful = tempEmail == account.getEmail() &&
                     tempPass == account.getPassword();

        if (successful)
        {
            std::cout << "\nWelcome Back: " << account.getDisplayName() << "\n\n";
        }
        else
        {
            std::cerr << "Invalid email or password!\n";
        }
    }
    return successful;
}

/*
 * @loginMenu()
 *
 * This function works with the switch statement in main.
 * It is another switch statement that provides existing user functions.
 */

void loginMenu(std::vector<Account> &accounts)
{
    bool loggedIn = validLogin(accounts);

    if (!loggedIn) { return; }

    std::size_t choice_menu2 = 0;

    do
    {
        gameMenu();
        choice_menu2 = getChoice();
        std::cin.ignore();

        switch (choice_menu2)
        {
            case 1:
                changePassword(accounts);
                break;
            case 2:
                changeDisplayName(accounts);
                break;
            case 3:
                std::cout << "Currently playing...\n\n";
                break;
            case 4:
                logout(loggedIn, choice_menu2);
                break;
            default:
                std::cerr
                        << "Invalid choice!\n"
                        << "Try again: ";
        }
    } while (choice_menu2 != 4 && loggedIn);
}

/*
 * @gameMenu()
 *
 * This function prints a menu for existing users
 * after they have logged in.
 */

void gameMenu()
{
    std::cout
    << "1. Change password\n"
    << "2. Change display name\n"
    << "3. Play\n"
    << "4. Log out\n";
}

/*
 * @getChoice()
 *
 * This function returns a size_t value because the input can't be negative.
 * It returns the choice the user makes when logged in.
 */

std::size_t getChoice()
{
    std::cout << "What would you like to do?\n";

    std::size_t choice = 0;
    std::cin >> choice;

    return choice;
}

/*
 * @changePassword()
 *
 * This function changes users password after the
 * account is created.
 *
 * Validated by exception class in setter function.
 */

void changePassword(std::vector<Account> &accounts)
{
    if (accounts.empty()) { return; }

    std::cout << "Enter your email to change your password.\n";

    std::string tempEmail{};
    getline(std::cin, tempEmail);

    for (auto &account : accounts)
    {
        try
        {
            if (tempEmail == account.getEmail())
            {
                std::cout
                        << "Account found!\n"
                        << "Reset your password: ";

                std::string newPassword{};
                getline(std::cin, newPassword);

                //validated in setter function
                account.setPassword(newPassword);
                std::cout << "New password set!\n\n";
            }
            else
            {
                std::cerr << "Account not found!\n\n";
            }
        }
        catch (Account::InvalidAccount)
        {
            std::cerr << "Password error!\n\n";
        }
    }
}

/*
 * @changeDisplayName
 *
 * This function changes the users display name
 * after the account is created.
 *
 * Validated by exception class in setter function.
 */

void changeDisplayName(std::vector<Account> &accounts)
{
    if (accounts.empty()) { return; }

    std::cout << "Enter your current display name & password to change your display name.\n";

    std::string tempName{}, tempPass{};

    std::cout << "Display name: ";
    getline(std::cin, tempName);

    std::cout << "Password: ";
    getline(std::cin, tempPass);

    try
    {
    for (auto &account : accounts)
    {
        bool accountFound = tempName == account.getDisplayName() &&
                            tempPass == account.getPassword();
        if (accountFound)
        {
            std::cout
                    << "Account found!\n"
                    << "Change your display name: ";
            getline(std::cin, tempName);

            std::cout << '\n';

            account.setDisplayName(tempName);
            std::cout << "New display name set!\n\n";
        }
        else
        {
            std::cerr << "Invalid username or password!\n\n";
        }
    }
    }
    catch (Account::InvalidAccount)
    {
        std::cerr << "Display name error!\n\n";
    }


}

/*
 * @logout()
 *
 * This function confirms the users request
 * to logout.
 */

void logout(bool &loggedIn, std::size_t &choice_menu2)
{
    std::cout << "Are your sure you want to log out? (Y/N)";

    char logoutChoice = 0;
    std::cin.get(logoutChoice);

    std::cout << '\n';

    switch (logoutChoice)
    {
        case 'y':
        case 'Y':
            std::cout << "Goodbye! Thank you for playing!\n\n";
            loggedIn = false;
            break;
        case 'n':
        case 'N':
            choice_menu2 = 3;
            break;
        default:
            std::cerr << "Error invalid input!\n";
    }
}
