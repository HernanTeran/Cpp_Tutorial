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

// Hernan Teran 1/16/2021 [ 1 ]

/*
*			++++++++       +          +
*			+              +          +
*			+          +++++++++  +++++++++
*			+              +          +
*			++++++++       +          +
*/

// [ 2 ]
#include <iostream>

// [ 5 ]
void displayMenu();
void displayResult();
void errorMessage();

// [ 3 ]
int main()
{
	// [ 4 ]

	std::cout << "{Enter a value}\n";

	std::cout
		<< "\nSI Units Convertor\n"
		<< "------------------\n"
		<< "1. miles to meters\n"
		<< "2. grams to kilograms\n"
		<< "3. minutes to seconds\n\n";

	std::cerr << "[Error]: invalid input!\n";

	// [ 7 ]
	displayMenu();
	displayResult();
	errorMessage();

	// [ 8 ] - compile time errors

	return 0;
}

// [ 6 ]
void displayMenu()
{
	std::cout
		<< "SI Units Convertor\n"
		<< "------------------\n"
		<< "1. miles to meters\n"
		<< "2. grams to kilograms\n"
		<< "3. minutes to seconds\n";
}

void displayResult()
{
	std::cout << "Result: " << "...\n";
}

void errorMessage()
{
	std::cerr << "[Error]: invalid input!\n";
}
