#include "Account.h"
#include <iostream>
#include <utility>
#include <string>

//static variable
int Account::objectCount = 0;

//constructor used to create an account
Account::Account(std::string mail, std::string pass, std::string DOB)
:
email(std::move(mail)),
password(std::move(pass)),
dateOfBirth(std::move(DOB))
{
    bool invalidAccount = InvalidEmail() || InvalidPassword() || InvalidDOB();

    if (invalidAccount)
    {
        throw InvalidAccount();
    }
    else
    {
        accountCreated = true;
        ++objectCount;
        greeting();
    }
}

//getters

const std::string &Account::getEmail() const
{
    return email;
}

const std::string &Account::getPassword() const
{
    return password;
}

const std::string &Account::getDisplayName() const
{
    return displayName;
}

const std::string &Account::getDateOfBirth() const
{
    return dateOfBirth;
}

int Account::getObjectCount()
{
    return objectCount;
}

bool Account::isAccountCreated() const
{
    return accountCreated;
}

//setters

void Account::setDisplayName(const std::string &name)
{
    auto validCharacter = [](const char &c) { return std::isalpha(c) || std::isdigit(c); };

    for (const char &c : name)
    {
        if (validCharacter(c))
        {
            Account::displayName = name;
        }
        else
        {
            throw InvalidAccount();
        }
    }
}

void Account::setPassword(const std::string &pass)
{
    Account::password = pass;
}

//other

void Account::greeting() const
{
    std::cout << "Welcome to RuneScape!\n";
}

//validators

//validate email
bool Account::InvalidEmail()
{
    //validating find
    //checking username
    std::size_t firstPosition = 0,
                user_atPosition = email.find('@');

    //checking domain name
    std::size_t domain_atPosition = email.find('@') + 1,
                dotPosition = email.find('.') - domain_atPosition;


    std::size_t TLD_Position = email.find('.'), //checking TLD
                notFound = std::string::npos; //used to make comparisons

    bool invalidInput = user_atPosition == notFound ||
                        domain_atPosition == notFound ||
                        dotPosition == notFound ||
                        TLD_Position == notFound;

    //validating lengths
    std::string findUserName = email.substr(firstPosition, user_atPosition),
                findDomain = email.substr(domain_atPosition, dotPosition),
                findTLD = email.substr(TLD_Position + 1, std::string::npos);

    bool invalidLength = findUserName.length() < 5 ||
                         findUserName.length() > 20 ||
                         findDomain.length() < 3 ||
                         findDomain.length() > 7 ||
                         findTLD.length() < 3 ||
                         findTLD.length() > 3;

    return invalidInput || invalidLength;
}

//validate password
bool Account::InvalidPassword()
{
    bool invalidLength = password.length() < 5 || password.length() > 20;

    //exit 1
    if (invalidLength)
    {
        return invalidLength;
    }

    int upperCount = 0,
        digitCount = 0,
        invCharCount = 0;

    for (const char &c : password)
    {
        if (std::isalpha(c))
        {
            if (std::isupper(c))
            {
                if (upperCount == 1)
                {
                    continue;
                }
                ++upperCount;
            }
        }
        else if (std::isdigit(c))
        {
            if (digitCount == 1)
            {
                continue;
            }
            ++digitCount;
        }
        else
        {
            if (invCharCount == 1)
            {
                break;
            }
            ++invCharCount;
        }
    }

    bool invalidPassword = upperCount == 0 ||
                           digitCount == 0 ||
                           invCharCount == 1;

    return invalidPassword;
}

//validate date of birth
bool Account::InvalidDOB()
{
    //validate length
    bool invalidLength = dateOfBirth.length() != 10;

    //exit 1
    if (invalidLength)
    {
        return invalidLength;
    }

    //validate only digits are used excluding dashes
    auto notDigit = [](const char &c) { return !std::isdigit(c); };
    bool invalidCharacters = true;

    //exit 2
    for (const char &c : dateOfBirth)
    {
        if (notDigit(c) && c != '/')
        {
            return invalidCharacters;
        }
    }

    //validate dashes
    std::size_t findDash_1 = dateOfBirth.find('/'),
                findDash_2 = dateOfBirth.find_last_of('/');

    std::size_t endOfString = std::string::npos;

    bool noDashes = findDash_1 == endOfString || findDash_2 == endOfString;

    //exit 3
    if (noDashes)
    {
        return noDashes;
    }

    //validate DD/MM/YYYY
    std::string findDay = dateOfBirth.substr(0, findDash_1),
                findMonth = dateOfBirth.substr(findDash_1 + 1, findDash_2 - 3),
                findYear = dateOfBirth.substr(findDash_2 + 1, endOfString);

    //first validate month
    enum class DaysOfMonth{January = 31, February = 28, March = 31,
                           April = 30, May = 31, June = 30, July = 31,
                           August = 31, September = 30, October = 31,
                           November = 30, December = 31};

    //functions that convert values to int
    auto to_digit = [](const std::string &input) { return std::stoi(input); };
    auto enum_to_digit = [](const DaysOfMonth month) { return static_cast<int>(month); };

    std::size_t monthDigit = to_digit(findMonth),
                validMonth = 0;

    bool invalidMonth = false;

    switch (monthDigit)
    {
        case 1:
            validMonth = enum_to_digit(DaysOfMonth::January);
            break;
        case 2:
            validMonth = enum_to_digit(DaysOfMonth::February);
            break;
        case 3:
            validMonth = enum_to_digit(DaysOfMonth::March);
            break;
        case 4:
            validMonth = enum_to_digit(DaysOfMonth::April);
            break;
        case 5:
            validMonth = enum_to_digit(DaysOfMonth::May);
            break;
        case 6:
            validMonth = enum_to_digit(DaysOfMonth::June);
            break;
        case 7:
            validMonth = enum_to_digit(DaysOfMonth::July);
            break;
        case 8:
            validMonth = enum_to_digit(DaysOfMonth::August);
            break;
        case 9:
            validMonth = enum_to_digit(DaysOfMonth::September);
            break;
        case 10:
            validMonth = enum_to_digit(DaysOfMonth::October);
            break;
        case 11:
            validMonth = enum_to_digit(DaysOfMonth::November);
            break;
        case 12:
            validMonth = enum_to_digit(DaysOfMonth::December);
            break;
        default:
            invalidMonth = true;
    }

    //using month to validate day
    std::size_t dayDigit = to_digit(findDay);

    bool invalidDay = true;

    for (std::size_t i = 1; i <= validMonth; ++i)
    {
        if (dayDigit == i)
        {
            invalidDay = false;
            break;
        }
    }

    //validate year
    std::size_t yearDigits = to_digit(findYear);
    bool invalidYear = yearDigits < 1950 || yearDigits > 2021;

    //main exit
    return invalidDay || invalidMonth || invalidYear;
}
