#include <iostream>
#include <iomanip>
#include <string>
#include <random>

/*
 *        Lesson 01
 * -------------------------
 * 1. comments
 * 2. preprocessor directive
 * 3. int main() { }
 * 4. data types
 * 5. variables
 * 6. arithmetic operators
 * 7. functions/references
 * 8. scope
 * 9. outputting data
 * 10. inputting data
 * 11. if/else statement
 * 12. exercises
 */

//function prototypes
char playedBefore();
int getCbLvl();
void damage(int&);
void currentHitPoints(int);
bool isAlive(int);
std::string eat();
void heal(const std::string&, int&);
int regulateHealth(int&);

void displayInput(char, int, bool, const std::string&, int, double);

int main()
{
    //int
    //variable definition
    int goblinLvl;

    //variable assignment
    goblinLvl = 5;

    //string
    //variable initialization
    std::string goblinWeapon = "spear";

    /********************************************/

    /*
     * Arithmetic Operators
     * --------------------
     * ( + ) - addition
     * ( - ) - subtraction
     * ( * ) - multiplication
     * ( / ) - division
     * ( % ) - modulus ( only works with int )
     *
     * Combined Operators
     * ------------------
     * ( += )
     * ( -= )
     * ( *= )
     * ( /= )
     * ( %= )
     */

    /********************************************/

    //      ( 1 ) - char
    char playExp;
    playExp = playedBefore();

    /********************************************/

    //      ( 2 ) - int
    int myCbLvl;
    myCbLvl = getCbLvl();

    /********************************************/

    /*
     *      ( 3 ) - bool
     *
     * Relational Operators
     * --------------------
     * ( > ) - greater than
     * ( < ) - less than
     * ( >= ) - greater than or equal to
     * ( <= ) - less than or equal to
     * ( == ) - equal to
     * ( != ) - not equal to
     *
     * Logical Operators
     * -----------------
     * && - AND
     * || - OR
     * ! - NOT
     */

    bool isDead;

    int hitPoints = 100;

    damage(hitPoints);

    currentHitPoints(hitPoints);

    //1 equals true, 0 equals false
    isDead = isAlive(hitPoints);

    /********************************************/

    //      ( 4 ) - string
    std::string foodItem = eat();

    heal(foodItem, hitPoints);

    currentHitPoints(hitPoints);

    /********************************************/

    //     ( 5 ) - double
    double moneyPouch;
    moneyPouch = 455'889.89;

    double moneyDrop;
    moneyDrop = 23'992.88;

    moneyPouch += moneyDrop;

    /********************************************/

    //     ( 6 ) - void
    displayInput(playExp, myCbLvl, isDead, foodItem, hitPoints, moneyPouch);

    return 0;
}

/*
 * Input / Output/ Errors
 * ----------------------
 * std::cout << output << '\n';
 * 
 * std::cin >> input;
 * 
 * std::cin.get(); - input for char
 * 
 * getline(std::cin, stringVar) - input for string
 * 
 * std::ignore() - use before using get/getline and after using cin
 * 
 * std::cerr << error message << '\n';
 */

//function definitions

char playedBefore()
{
    char tempInput;

    //prompt
    std::cout << "Have you ever played Runescape before? (Y or N)\n";

    //remember char can only hold a single character
    std::cin.get(tempInput);

    return tempInput;
}

int getCbLvl()
{
    int cbLvlTemp;

    std::cout << "What is your combat level?\n";

    std::cin >> cbLvlTemp;

    return cbLvlTemp;
}

void damage(int& hitPoints)
{
    // Generating Random Numbers
    std::random_device rd;  //Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<> damage(0, 25); // range of random numbers (0 - 25)

    //same as hitPoints = hitPoints - damage(gen);
    hitPoints -= damage(gen);
}

void currentHitPoints(const int hitPoints)
{
    std::cout << "Current HP: " << hitPoints << '\n';
}

bool isAlive(int hitPoints)
{
    //if true
    if (hitPoints > 0 && hitPoints < 100)
    {
        //do this
        return true;
    }
        //if false
    else
    {
        //do this (depends on return type)
        return false;
    }
}

std::string eat()
{
    std::string foodTemp;

    std::cout << "What are you going to eat?\n";

    //cin.ignore() clears buffer
    std::cin.ignore();

    //getline is used to get string input
    getline(std::cin, foodTemp);

    return foodTemp;
}

void heal(const std::string& foodItem, int& hitPoints)
{
    int health;

    /*
     * ( == ) is not the same as ( = )
     *
     * == represents equality by comparison
     *
     * = is the assignment operator
     */

    if (foodItem == "lobster")
    {
        health = 20;
        hitPoints += health;
        hitPoints = regulateHealth(hitPoints);
    }
        //another if statement
    else if (foodItem == "shrimp")
    {
        health = 10;
        hitPoints += health;
        hitPoints += regulateHealth(hitPoints);
    }
    else
    {
        health = 2;
        hitPoints += health;
        hitPoints = regulateHealth(hitPoints);
    }
}

int regulateHealth(int& HP)
{
    //ternary operator
    HP = HP > 100 ? 100 : HP;

    HP = HP < 0 ? 0 : HP;

    return HP;
}

void displayInput(const char playExp, const int myCbLvl, bool isAlive, const std::string& foodItem, const int hitPoints, const double moneyPouch)
{
    std::cout << std::setprecision(2) << std::fixed
              << "\nPlayed RS before: " << playExp << '\n'
              << "Combat level: " << myCbLvl << '\n'
              << "Is alive: " << isAlive << '\n'
              << "Food item that healed you: " << foodItem << '\n'
              << "Current HP: " << hitPoints << '\n'
              << "Amount in money pouch: $" << moneyPouch << '\n';
}

/*
 *                      Summary
 * ---------------------------------------------------------
 * 1. use comments to describe purpose
 * 2. be mindful of where you make declarations (errors)
 * 3. make functions perform only 1 action
 * 4. make identifiers meaningful
 * 5. C++ is case sensitive
 * 6. be mindful of scope
 * 7. prefer '\n' over endl;
 * 8. avoid repetitive code
 * 9. use const whenever possible
 * 10. use cin.ignore() for char/string after using cin >>
 * 11. the goal is to keep code simple and readable
 * 12. pass by value with const
 * 13. pass by reference if updating the variable
 * 14. inline potential if statements...if possible
 */

/*
 *                            Exercises
 * ------------------------------------------------------------------
 * 1. Create a program that has a void function called examine and
 *    a const string as its parameter.
 *
 *    Create 3 different strings to represent 3 different NPCs
 *    Use a prompt to get which NPC you currently want to examine.
 *    Then use an if/else statement to execute the NPCs respective
 *    description.
 *
 * 2. Create a program that updates your run energy.
 *    Max run is 100.
 *
 *    There should be a function that states your running.
 *    ( Only if your run energy is > 0 && < 100 )
 *    It should subtract 25 from your run energy (in main)
 *    every time that you call it.
 *
 *    There should be a function that states your walking.
 *    ( It should also restore your run energy by 25
 *      every time you call until it is back to 100 )
 *
 *    There should be a function that states you ran out of run energy.
 *
 *    There should be a function that restores your run energy
 *    to 100 by drinking an energy potion.
 *    ( With it, there should a be a prompt that asks whether
 *      or not your sure you want to drink the potion. Your input
 *      should be of type char. )
 *
 * 3. Create a program that asks for your login information,
 *    your member status, and then displays all this information.
 *
 * 4. Create a program that updates your money pouch.
 *    You should be prompted to enter how much gp you got
 *    from your drop, then add that to your pouch.
 *
 *    Each time you add to your pouch, the current
 *    amount should be displayed as well as much
 *    was added.
 *
 *    You should also create a function that withdraws
 *    from your pouch. This should result from a prompt.
 *    If your money pouch is empty, display an error message
 *    (using std::cerr instead of std::cout) stating that
 *    your pouch is empty and you can't withdraw anything.
 *
 *    This includes keeping your pouch at 0, if empty, and
 *    not letting it display a negative number. For example,
 *    you have 100 coins left and you withdraw 200 coins...
 *    it will withdraw the 100 but give you the error message
 *    stating that you don't have enough to withdraw your
 *    requested amount. Your pouch would equal 0 as opposed to
 *    -100.
 *
 *    Display the current amount in your pouch after all
 *    withdrawals.
 *
 *    Use int to represent your variables.
 *    Keep your pouch under 1,000,000.
 *
 *    5. Create a program that uses a bool variable called
 *    isMember, it should be set to false.
 *
 *    Combine this with exercise #3. After you log in, you
 *    should get a prompt asking if you would like to become a member.
 *    If you choose yes, then it will give you a message
 *    and update isMember to true.
 *
 *    If you choose no, it'll give you a message and leave
 *    isMember as is.
 *
 *    After you become a member, there should be a function
 *    that prevents you from getting prompted about
 *    membership again by checking isMember. Instead it should
 *    state you are already a member after you call the function
 *    that logs you in.
 */
