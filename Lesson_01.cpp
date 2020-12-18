// # - preprocessor directive. This sets up the source code for the compiler
// #include - includes the contents of a header file
// <iostream> - wrapped in enclosed brackets, names of the files, allows input and output (input/output library)
// using namespace std; - gives access to the entities of the Standard Library
// C++ is case sensitive

#include <iostream>
#include <string>

void ranOut();

// a function - value/type name() { }

int main()
// opening brace
{
    // console output : String  : end output
    std::cout << "Running..." << std::endl; // ; include semi-colons at the end of statements

    /*
     * Assignment Statement
     *
     * ( int ) - integer
     * ( char ) - character
     * ( string ) - collection of characters
     * ( double ) - floating point
     * ( bool ) - boolean, true, false
     *
     * variables are storage locations in the computer's memory
     * literals are constant values that are assigned to variables
     *
     * identifies can only be written with letters, digits, or underscores
     * identifiers can't be any of the reserved keywords
     * make identifiers meaningful
     * use camel case or underscores
     *
     * = is the assignment operator
     *
     * always be mindful of scope
     *
     * use const whenever possible if it makes sense to
     */

    // variable definition - type identifier (name);
    std::string playerName;

    // assignment - variable name = literal (values/constants);
    playerName = "Gamebot676";

     /*
      * Outputting Data
      *
      * cout - stream object that works with a stream of data
      * << - stream insertion operator. Works with cout to output data
      * endl - stream manipulator. Creates a newline
      * newline escape sequence - can also use "\n"
      */

    // output       :            variable      :    end output;
    std::cout << "The player " << playerName << " is running...\n";

    // initialization
    int runEnergy = 100;

    std::cout << playerName << " has " << runEnergy << " run energy...\n";

    double money_pouch = 1234.56;

    char memberStatus = 'N';

    // 0 = false, 1 = true
    bool isRich = false;

    /*
     * Arithmetic Operators
     *
     * unary, binary, ternary
     *
     * ( + ) - addition
     * ( - ) - subtraction
     * ( / ) - division
     * ( * ) - multiplication
     * ( % ) - modulus (returns remainder... (bigNumber % littleNumber)
     *
     */

    runEnergy = runEnergy - 23;

    money_pouch = money_pouch / 2;


    std::cout
    << "Player name: " << playerName << '\n'
    << "Current run energy: " << runEnergy << '\n'
    << "Member status: " << memberStatus << '\n'
    << "Is rich: " << isRich << '\n'
    << "Amount in money pouch: " << money_pouch << '\n';

    /*
     * Introduction to Functions
     *
     * returnType functionName() { code }
     * called in main by writing out the declaration out
     *
     * void ranOut(); notice the semicolon
     */

    ranOut();

    // return returns the corresponding value back to the operating system upon the program's completion
    return 0;
}
// closing brace

void ranOut()
{
    std::cout << "You don't have enough energy left to run!\n";
}
