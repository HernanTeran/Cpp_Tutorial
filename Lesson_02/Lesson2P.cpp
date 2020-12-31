#include <iostream>

/*
 * Lesson 02
 *
 * 1. using booleans
 * 2. if/else
 * 3. else if
 * 4. inline statement
 * 5. logical operators/nested if/else statements
 * 6. switch statements
 */

bool ageReq1(int, int); //basic if statement
void ageReq2(int, int); //if/else if/else statement
bool inlineAgeReq(int, int);
void pay2Play_1(bool, bool); //nested if statements
bool pay2Play_2(bool, bool); //inlined logical operator statement
char getInput(bool);
bool switchPay2Play(char); //switch statement

int main()
{
    const int rsAge = 13;

    int yourAge;

    std::cin >> yourAge;

    bool isOver13;

    isOver13 = yourAge >= rsAge;

    //true is 1, false is 0
    std::cout << isOver13 << '\n';

    isOver13 = ageReq1(yourAge, rsAge);

    std::cout << isOver13 << '\n';

    //void so doesn't need to be assigned
    ageReq2(yourAge, rsAge);

    isOver13 = inlineAgeReq(yourAge, rsAge);

    std::cout << "**********************************\n";

    bool isMember = false;

    pay2Play_1(isMember, isOver13);

    int x;
    std::cin >> x;

    int y = x > 5 ? x : 5;
    std::cout << "y = " << y << '\n';

    std::cout << "**********************************\n";

    char input = getInput(isOver13);
    //assigning the result of the function to isMember
    isMember = switchPay2Play(input);

    return 0;
}

bool ageReq1(int yourAge, const int rsAge)
{
    if (yourAge >= rsAge)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool inlineAgeReq(int yourAge, const int rsAge)
{
    return yourAge >= rsAge;
}

void ageReq2(int yourAge, const int rsAge)
{
    if (yourAge >= rsAge)
    {
        std::cout << "Welcome to Runescape!\n";
    }
    else if (yourAge == 12)
    {
        std::cout << "One more year and then you can play!\n";
    }
    else
    {
        std::cout << "You're not old enough to play yet!\n";
    }
}

void pay2Play_1(bool isMember, bool isOver13)
{
    char promptInput;

    if (!isMember && !isOver13)
    {
        std::cout << "You are not old enough to play yet!\n";
    }
    //if isMember equals false
    //isMember != true
    else if (!isMember && isOver13)
    {
        std::cout
        << "Would you like to become a member?\n"
        << "Enter (Y or N)\n";

        //use cin.ignore() to clear buffer of extra '\n' characters
        std::cin.ignore();
        //use cin.get(varName) for char input
        std::cin.get(promptInput);

        //nested if/else statement using the OR logical operator
        if (promptInput == 'Y')
        {
            //updating isMember's value to true
            isMember = true;
            std::cout << "You are now a member! Enjoy!\n";
        }
        else if (promptInput == 'N')
        {
            //isMember remains false
            std::cout << "Hopefully you become a member soon!\n";
        }
        else
        {
            //isMember remains false
            std::cout << "Input was suppose to be Y or N!\n";
        }
    }
    else
    {
        //isMember was already true
        std::cout << "You are already a member!\n";
    }
}

bool pay2Play_2(bool isMember, bool isOver13)
{
    return isMember && isOver13;
}

char getInput(bool isOver13)
{
    std::cout
    << "Would you like to become a member?\n"
    << "Enter (Y or N)\n";

    char promptInput;

    std::cin.ignore();
    std::cin.get(promptInput);

    if ((promptInput == 'Y' || promptInput == 'y') || (promptInput == 'N' || promptInput == 'n') && isOver13)
    {
        return promptInput;
    }
   return promptInput;
}

bool switchPay2Play(char input)
{
    char promptInput = input;

    bool isMember = false;

    switch (promptInput)
    {
        case 'Y':
        case 'y':
            isMember = true;
            std::cout << "You are now a member! Enjoy!\n";
            break;
        case 'N':
        case 'n':
            std::cout << "Hopefully you become a member soon!\n";
            break;
        default:
            std::cout << "Input was suppose to be Y or N!\n";
    }
    return isMember;
}
