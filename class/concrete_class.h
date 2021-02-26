// $Header$
//----------------------------------------------------------------------------------------------------------------------------------
//                                               Concrete Class
//----------------------------------------------------------------------------------------------------------------------------------
// ACRONYM: Project Name
//
// Author: Hernan Teran
// Created: yyyy/mm/dd
//
/*
* Class or namespace
* description
*/
//----------------------------------------------------------------------------------------------------------------------------------
#ifndef CLASS_H
#define CLASS_H
#pragma once

//----------------------------------------------------------------------------------------------------------------------------------
// source files/translation units
//----------------------------------------------------------------------------------------------------------------------------------
/*
* a name that can be used in translation units different from the one in which it was defined
* has external linkage.
* 
* a name that can be referred to only in the translation unit in which it is defined has
* internal linkage. By default const/constexpr objects, type aliases, and anything
* declared static has internal linkage. const objects can use the prefix extern to have external
* linkage.
* 
* use a driver to run the program then have main run the driver
*/
//----------------------------------------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------------------------------------
// namespaces + using declarations/directives
//----------------------------------------------------------------------------------------------------------------------------------
/*
* don't use using declarations/directives globally or in header files
* instead place them within functions but make sure names still won't clash
* you can update a namespace by declaring it and then add functions/classes
* use using directives if a name is used more than 5 times
* use full names if a name is uncommon
* use namespace aliases for long names: namespace Short = Long_Name;
*/
//----------------------------------------------------------------------------------------------------------------------------------

namespace Classes
{
	class Class
	{
//----------------------------------------------------------------------------------------------------------------------------------
		// enum class
		/*
		* an enum or enumeration specifies a set of symbolic integer constants called enumerators
		* 
		* plain enums allow implicit conversions to int
		* plain enum enumerator names could clash with other names like from iostream
		*/
//----------------------------------------------------------------------------------------------------------------------------------
	public:
		// user interface

		// exception class
		// constructors
		// default constructor
		// destructor

//----------------------------------------------------------------------------------------------------------------------------------
// copy operations
//----------------------------------------------------------------------------------------------------------------------------------
/*
* the copy of a class object is memberwise copy by default
* 
*/
//----------------------------------------------------------------------------------------------------------------------------------

		// don't inline functions that are >= 5

		// nonmodifying operations

		// modifying operatios

		void print();
	protected:
	private:
		// implementation details
	};

//----------------------------------------------------------------------------------------------------------------------------------
// helper functions
//----------------------------------------------------------------------------------------------------------------------------------
/*
* any functions that modify that state of an object should return a reference
* to the object by using *this
* EX: ClassName& add_year(int n) { return *this; }
*/
//----------------------------------------------------------------------------------------------------------------------------------

	int add();

	// operator overloading
	bool operator==(const Class& obj1, const Class& obj2);

	std::ostream& operator<<(std::ostream& os, Class& obj);
	std::istream& operator>>(std::istream& is, const Class& obj);

	// Reference objects: ++, --, +=, -=
	// Value objects: +, -, *, /

	Class operator++(Class& c);
	Class operator+(const Class& obj1, const Class& obj2);
	Class operator+=(const Class& obj, int num);

	// function to initialize default constructor
	const Class& default_class()
	{
		static Class cc{}; // values
		return cc;
	}
}

#endif // CLASS_H
