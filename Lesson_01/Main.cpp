#include <iostream>
#include <string>

/*
 * A type defines a set of possible values and a set of operations (for an object).
 * An object is some memory that holds a value of some type.
 * A value is a set of bits interpreted according to a type.
 * A variable is a named object.
 *
 * make a date and password(one to create a password and one as login) class
 */
#include "AccountInfo.h"

std::string getEmail();
std::string getPassword();
std::string getDOB();

int main()
{
    std::string email, password, DOB;

    email = getEmail();

    password = getPassword();

    DOB = getDOB();



    return 0;
}

std::string getEmail()
{
    std::cout << "Enter your email: ";
    std::string email;
    getline(std::cin, email);
    return email;
}
