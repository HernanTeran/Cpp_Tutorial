#include <iostream>

/*
 *        Lesson 01
 * -------------------------
 * 1. comments
 * 2. preprocessor directive
 * 3. int main() { }
 * 4. data types
 * 5. variables
 * 6. functions
 * 7. scope
 * 8. arithmetic operators
 * 9. outputting data
 * 10. inputting data
 */

//function prototypes
void examine();
void running(int); //only data type needs to be written in a prototype parameter
int usedEnergy(int, int);
void zeroEnergy();

int main()
{
    //variable definition
    int goblinLvl;

    //variable assignment
    goblinLvl = 5;

    //variable initialization
    std::string goblinWeapon = "spear";

    //define booleans like isSomething
    bool isDead;

    char getInput;

    //prompt
    std::cout << "Have you ever played Runescape before? (Y or N)" << '\n';

    //remember char can only hold a single character
    std::cin >> getInput;

    //getInput now either has the value 'Y' or 'N' assigned to it
    std::cout << "Your input: " << getInput << '\n';

    int myCbLvl, lvlDiff;

    myCbLvl = 121;

    lvlDiff = myCbLvl - goblinLvl;

    //calling functions

    //since it's void it doesn't need to be assigned to a variable
    examine();

    //read only
    const int maxEnergy = 100;

    std::cout << "Enter current run energy: ";

    int runEnergy;

    std::cin >> runEnergy;

    //when a function uses a value the parameter value is called an argument
    running(runEnergy);

    //usedEnergy must be assigned to int because it returns an int
    //input arguments according to parameter order
    int usedRun = usedEnergy(maxEnergy, runEnergy);

    //if zero energy left (we'll expand on this in the next lesson)
    zeroEnergy();

    double moneyPouch;

    //use ' for better readability with big numbers
    moneyPouch = 522'435;

    moneyPouch += 300'000;
    //moneyPouch -= 150,000;
    //moneyPouch *= 2;
    //moneyPouch /= 2.5;

    std::cout << "gp: " << moneyPouch << '\n';

    //modulus - (bigNumber % littleNumber)
    int modulusEx = maxEnergy % usedRun;

    std::cout
        << "Example: " << modulusEx << " is the remainder of "
        << maxEnergy << ' % ' << usedRun << '\n';

}

//function definitions

void examine()
{
    std::cout << "An ugly green creature.\n";
}

//will output a message + the value of runEnergy
void running(int runEnergy)
{
    std::cout
    << "Running...\n"
    << "Current run energy: " << runEnergy << '\n';
}

//returns an integer
int usedEnergy(const int maxEnergy, int runEnergy)
{
    return maxEnergy - runEnergy;
}

void zeroEnergy()
{
    std::cout << "You don't have enough energy left to run!\n";
}
