#include <iostream>
#include <string>

// math library
#include <cmath>
// used to format output
#include <iomanip>
// used to generate random numbers
#include <random>

// function prototype
// returnType name(types);
void running(int);

int main()
{
    /*
     * Inputting Data
     *
     * cin - cin object reads data typed at the keyboard
     * getline - used with strings
     * get - used with char
     * cin >> - used with int, double
     *
     * >> is the stream extraction operator
     *
     * cin >> - (coming in) - can enter multiple values at once
     * cout << - (going out)
     */

    // initialized variable
    std::string playerName;

    // prompt
    std::cout << "Enter your user name: ";

    // getline(cin, variableName);
    getline(std::cin, playerName);

    int runEnergy;

    std::cout << "\nEnter your current run energy: ";
    std::cin >> runEnergy;

    std::cout << playerName << " has " << runEnergy << " run energy...\n";

    /*
     * Formatting Output
     *
     * setw(value) - creates space
     * setprecision(value) - formats double by rounding
     * fixed - formats double by producing fixed-point notation
     */

    double moneyPouch = 83'323.83,
           gpDrop = 42'332.88;

    moneyPouch += gpDrop;

    // gp = gold pieces, moneyPouch is rounded
    std::cout << std::setprecision(2) << std::fixed << moneyPouch << " gp\n";

    // if it were in dollars
    std::cout << std::setprecision(2) << std::fixed << '$' << moneyPouch << '\n';

    /*
     * More On Strings
     *
     * length is the total number of characters in a string
     * the count begins with 0 not 1
     * last character is the newline character
     * concatenation is the process of combining 2 or more strings
     */

    int nameLength = playerName.length();
    std::string randomStatement = playerName + " is not a member.";

    std::cout
    << "Player name length: " << nameLength << " characters\n"
    << "Concatenation: " << randomStatement << '\n';

    // Generating Random Numbers
    std::random_device rd;  //Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<> rand(1, 10); // range of random numbers (1 - 10)

    // rand(gen) outputs a random number
    std::cout << rand(gen) << "\n";

    /*
     * A Word About Operations
     *
     * use PEMDAS to properly execute operations
     *
     * raise to power - pow(variableName, power);
     * absolute value - abs(value);
     * square root - sqrt(value);
     *
     * combined assignment:
     * ( += )
     * ( -= )
     * ( *= )
     * ( /= )
     * ( %= )
     */

    // using random number to alter run energy
    std::uniform_int_distribution<> randomEnergy(1, 10);

    // same as runEnergy = runEnergy ( operator ) value;
    runEnergy += randomEnergy(gen);
    runEnergy -= randomEnergy(gen);
    runEnergy /= randomEnergy(gen);
    runEnergy *= randomEnergy(gen);

    /*
     * Using Functions
     *
     * function call - functionName(arguments); - if any otherwise just ()
     * arguments are the corresponding variable names
       according to the type that is being called in the function
     *
     * functions are used to create clean and organized code
     */

    // functionName(argument);
    // runEnergy is the int argument that provides what
    // the function running needs in its parameters to work
    // in this case it only needs 1 integer
    running(runEnergy);

    return 0;
}

    /*
     * Introduction to Working With Booleans
     *
     * uses if/else statement
     * example use >, &&, and < conditional operators
     *
     * if - this is true/false, do this
     * else - if it wasn't true/false, (whatever you wanted), do this
     */

// returnType name(type parameterName) { code }
void running(int runEnergy)
{
    // if true
    if (runEnergy > 0 && runEnergy < 100)
    {
        // do this
        std::cout
        << "Running...\n"
        << "Current run energy: " << runEnergy << '\n';
    }
    // if not true
    else
    {
        // do this
        std::cout
        << "You don't have enough energy left to run!\n"
        << "Walking...\n";
    }
}
