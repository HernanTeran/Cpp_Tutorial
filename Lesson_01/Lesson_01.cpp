#include <iostream>
#include <vector>
#include <string>


/*
* 1 - introduce parts of a C++ program/cheesecake example/cout prompts/cerr errors/introduce void function/compile time errors
* 2 - introduce types/operators/physics/cmath library - (only into to operators)/<iomanip>/pass parameters into void/link-time errors
* 3 - functions/operators/const-constexpr/if-else/switch/ternary/run-time errors/goal is to do functions for conversions-computation
* 4 - loops-for-while/vectors/iterator/logic errors/exceptions/goal is to fill results(temperature) in a vector
* 5 - functions in depth (pass by reference)/scope/namespaces/enum class/templates/do uncertainty experiment
* 6 - structs/map/algorithms/more on vectors/iterators/lambdas/the walking physics idea
* 7 - reading/writing files/regex/my car experiment
* 8 - classes/RAII/copy/move/this pointer - use cheesecake as example/gas station 
* 9 - abstract class/virtural functions/overriding/inheritance/runescape
* 10 - sets/linked lists/arrays/matrix/example can be a song queue
* 11 - pointers/smart pointers/example can be a bankaccount. (your money is in bankaccount, accessing through app or atm points to your money
*      virtually.
*/

/*
* graham cracker crust -class
* 910g cream cheese-int
* 200g sugar-int
* 160g sour cream-int
* 7.5g (1.5 teaspoons) vanilla extract -double
* 0.5g (1/8) teaspoons salt
* 4 large eggs - vector of 12 eggs
* mixing bowl-class
* oven-class
* 
* 
* menu - add ingredients, 
*/

/*
* What are the C++ data types?
* ----------------------------
* 1. ( int ) - positive/negative integer
* 2. ( double ) - double precision floating point
* 3. ( char ) - a character enclosed in single quotes
* 4. ( string ) - a sequence of characters (char) enclosed in double quotes
* 5. ( bool ) - boolean which represents true or false ( 1 or 0 )
*
* How are the data types implemented?
* -----------------------------------
* 1. they are used to define object types
* 2. they are used to define function return types
*
* What is an object?
* ------------------
* An object is a region in memory that holds a value with a given type.
* 
* What is a value?
* ----------------
* A set of bits in memory that is interpreted by type.
*
* What is a variable?
* -------------------
* A variable is a named object. When working with data you work with
* either variables or literals.
* 
* What is a literal?
* ------------------
* A literal is just what it sounds like. It is a value that 
* represents its corresponding type.
*
* How is a variable defined?
* --------------------------
* 1. type name; // declaration, uninitialized, memory is set aside
* 2. type name{value}; // initialized according to type
* 3. type name = value; // assignment according to type
*
* What is a function?
* -------------------
* A function is a sequence of statements that return a value
* defined by a data type.
*
* How is a function defined?
* --------------------------
* type name(parameter list) { // code; }
*
* type - data type
* name - whatever you like as long as it's legal
* (parameter list) - parameters are the values that a function works with to return a value
*                  - parameters are stored within parenthesis
*                  - a function does not have to have parameters to return a value
*
* { } - curly braces must be used to contain the function code
* function body - the function code
* semi-colon - a semi-colon is used to terminate C++ statements
*
* What does void mean?
* --------------------
* Void is a function type that means the function doesn't return a value.
*/


int main()
{
    /*
    * Input / Output / Errors
    * -----------------------
    *
    * cout - character output stream
    * << - insertion operator
    *
    * std::cout << output << '\n';
    *
    * cin - character input stream
    * >> - extraction operator
    *
    * std::cin >> input;
    *
    * cerr - error output stream
    * std::cerr << error message << '\n';
    *
    * std::cin.get(); // input for char
    *
    * getline(std::cin, stringVar) // input for string
    *
    * std::ignore() // use before using get/getline and after using cin
    */

    //variable definition/initialization 
    int goblinLvl{ 0 };

    //variable assignment
    goblinLvl = 42;

    /*
    *            int
    *           ------
    * goblinLvl:| 42 |
    *           ------
    */

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
    char playExp{ 0 };
    playExp = 'Y';

    /********************************************/

    //      ( 2 ) - int
    int myCbLvl{ 0 };
    myCbLvl = 121;

    /********************************************/

    /*
    * 
    * 
    * 
    * 
    */

    //      ( 3 ) - string
    std::string npcName{ "npc" };
    npcName = "Goblin";

    /********************************************/

    //      ( 4 ) - double
    double moneyPouch{ 0.0 };
    moneyPouch = 455'889.89;

    double gpDrop{ 23'992.88 };

    moneyPouch += gpDrop;

    /********************************************/

    /*
           ( 5 ) - bool

      Relational Operators
      --------------------
      ( > ) - greater than
      ( < ) - less than
      ( >= ) - greater than or equal to
      ( <= ) - less than or equal to
      ( == ) - equal to
      ( != ) - not equal to

      Logical Operators
      -----------------
      && - AND
      || - OR
      ! - NOT

      1 == true
      0 == false
    */

    bool isDead{ false };

    constexpr int maxHitPoints{ 100 };

    int currentHitPoints{ 82 },
        damageTaken{ 0 };

    damageTaken = maxHitPoints - currentHitPoints;

    std::cout << "Damage taken: " << damageTaken << '\n';

    currentHitPoints -= 82;

    if (currentHitPoints == 0)
    {
        isDead = true;
    }

    if (isDead)
    {
        std::cout << "Oh dear, you are dead!\n";
    }
    else
    {
        std::cout << "Still alive...\n";
    }
    
    //regex
    std::vector<std::string> zipcodes{ "TX77070", "TH", "YU 45422-0923" };

	std::regex pat{ R"(\w{2}\s*\d{5}(-\d{4})?)" };
	
	std::smatch matches;

	bool found = std::regex_search(zipcodes.at(1), matches, pat);
	
	if (found) { std::cout << "found\n"; }
	else { std::cout << "not found\n"; }
    
    return 0;
}
