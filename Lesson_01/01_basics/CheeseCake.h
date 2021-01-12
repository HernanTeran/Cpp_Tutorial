#pragma once
#include <iostream>
#include <string>

// header file ( .h )
// class declarations
// private/public are called access specifiers

class CheeseCake
{
private: // implementation

	// data members
	int cream_cheese{ 0 };
	double white_sugar{ 0 };
	double sour_cream{ 0 };
	double vanilla_extract{ 0 };
	double salt{ 0 };
	int eggs{ 0 };
	std::string crust_type;
	
public: // interface

	// constructor
	CheeseCake() = delete;

	// destructor
	~CheeseCake() { std::cout << "Object has been destroyed by destructor.\n"; }
};
