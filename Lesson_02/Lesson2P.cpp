// Hernan Teran 1/17/2021

#include <iostream>
#include <string>
#include <cmath> // [ 1 ]
#include <iomanip>

// [ 2 ]
std::string get_SI_Unit();
char get_SI_Abbrev();
double getInitialPos();
double getFinalPos();
double calculate_displacement(double, double);
void displayResult(double, std::string, char);
int raiseToPower();
void formatResult(double, std::string, char);

int main()
{
	// [ 3 ]
	std::string SI_Unit;
	SI_Unit = get_SI_Unit();

	char abbrev{ '0' };
	abbrev = get_SI_Abbrev();

	double initial_pos{ 0 };
	initial_pos = getInitialPos();

	double final_pos{ 0 };
	final_pos = getFinalPos();

	double displacement{ 0 };
	displacement = calculate_displacement(initial_pos, final_pos);
	displayResult(displacement, SI_Unit, abbrev);

	int power{ 0 };
	power = raiseToPower();

	// [ 7 ]
	
	// raise to power
	displacement = pow(displacement, power);
	displayResult(displacement, SI_Unit, abbrev);

	// rounding
	displacement = ceil(displacement);
	displayResult(displacement, SI_Unit, abbrev);
        
	// square root
	displacement = sqrt(displacement);
	displayResult(displacement, SI_Unit, abbrev);

	// [ 4 ]
	formatResult(displacement, SI_Unit, abbrev);

	// [ 8 ]
	std::cout
		<< "Size of: " << sizeof(displacement) << '\n'
		<< "Type: " << typeid(displacement).name() << '\n';

	// [ 9 ] - type safety
	// [ 10 ] - link time errors
	return 0;
}

// [ 5 ]
std::string get_SI_Unit()
{
	std::cout << "What is the SI unit for displacement?\n";

	std::string SI_Unit;
	getline(std::cin, SI_Unit);

	return SI_Unit;
}

char get_SI_Abbrev()
{
	std::cout << "Enter SI unit abbreviation.\n";

	char SI_Abbrev{ '0' };
	std::cin.get(SI_Abbrev);

	return SI_Abbrev;
}

double getInitialPos()
{
	std::cout << "Enter your initial position.\n";

	double initial_pos{ 0 };
	std::cin >> initial_pos;

	return initial_pos;
}

double getFinalPos()
{
	std::cout << "Enter your final position.\n";

	double final_pos{ 0 };
	std::cin >> final_pos;

	return final_pos;
}

double calculate_displacement(double initial_pos, double final_pos)
{
	return final_pos - initial_pos;
}

void displayResult(double result, std::string SI_Unit, char abbrev)
{
	std::cout << "Result: " << result << " " << SI_Unit << " (" << abbrev << ")\n";
}

int raiseToPower()
{
	std::cout << "To what power do you want to raise the result?\n";

	int power{ 0 };
	std::cin >> power;

	return power;
}

void formatResult(double result, std::string SI_Unit, char abbrev)
{
	std::cout << std::fixed << std::setprecision(2); // [ 7 ]
	displayResult(result, SI_Unit, abbrev);
}
