#ifndef CPP_PRACTICE_ACCOUNT_H
#define CPP_PRACTICE_ACCOUNT_H
#include <string>
#include <utility>

class Account
{
private:
    //variables
    std::string email, password, displayName, dateOfBirth;
    bool accountCreated = false;
    static int objectCount;

    //private functions
    void greeting() const;
    bool InvalidEmail();
    bool InvalidPassword();
    bool InvalidDOB();

public:
    //constructor used to create an account
    Account(std::string email, std::string password, std::string dateOfBirth);

    //throws error if invariant isn't established
    class InvalidAccount{};

    //getters
    const std::string &getEmail() const;
    const std::string &getPassword() const;
    const std::string &getDisplayName() const;
    const std::string &getDateOfBirth() const;
    bool isAccountCreated() const;

    //setters
    void setDisplayName(const std::string &displayName);
    void setPassword(const std::string &password);

    //other
    static int getObjectCount();

};

#endif //CPP_PRACTICE_ACCOUNT_H