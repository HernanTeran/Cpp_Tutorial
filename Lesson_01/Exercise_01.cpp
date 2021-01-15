#include <iostream>
#include <string>

int main()
{
	std::cout
		<< "About Me\n"
		<< "--------\n"
		<< "1. Full name\n"
		<< "2. 1 hobby\n"
		<< "3. Age\n"
		<< "4. First time programming? (y/n)\n"
		<< "5. Current temperature (use double)\n\n";

	std::string first_name,
		    last_name,
		    my_hobby;

	getline(std::cin, first_name);
	getline(std::cin, last_name);
	getline(std::cin, my_hobby);

	std::string full_name{ first_name + " " + last_name };

	int my_age{ 0 };
	std::cin >> my_age;

	std::cin.ignore();

	char first_program{ '0' };
	std::cin.get(first_program);

	double current_temp{ 0 };
	std::cin >> current_temp;

	std::cout
		<< "About Me\n"
		<< "--------\n"
		<< "1. " << full_name << '\n'
		<< "2. " << my_hobby << '\n'
		<< "3. " << my_age << '\n'
		<< "4. " << first_program << '\n'
		<< "5. " << current_temp << '\n';
		
	return 0;
}
