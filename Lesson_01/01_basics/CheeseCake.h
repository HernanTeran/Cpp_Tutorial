#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "CreamCheese.h"
#include "Sugar.h"
#include "SourCream.h"
#include "VanillaExtract.h"
#include "Salt.h"
#include "Egg.h"

// header file ( .h )
// class declarations
// private/public are called access specifiers
class CheeseCake
{
private:
	// implementation

	// data members
	CreamCheese cream_cheese;
	Sugar white_sugar;
	SourCream sour_cream;
	VanillaExtract vanilla_extract;
	Salt salt;
	std::vector<Egg> eggs;

	
public:
	// interface
	// constructor
	CheeseCake() = delete;

	~CheeseCake() { std::cout << "Object has been destroyed by destructor.\n"; }
};