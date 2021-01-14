#include "CheeseCake.h"

// source code file ( .cpp )
// class definitions

CheeseCake::CheeseCake(int c_cheese,
					   double w_sugar,
					   double s_cream,
					   double v_extract,
					   double salt_,
					   int n_eggs,
					   std::string crust)
					   :
					   cream_cheese(c_cheese),
					   white_sugar(w_sugar),
					   sour_cream(s_cream),
					   vanilla_extract(v_extract),
					   salt(salt_),
					   n_of_eggs(n_eggs),
					   crust_type(crust)
{
	std::cout << "Object has been created.\n";
}
