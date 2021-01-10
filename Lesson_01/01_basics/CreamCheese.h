#pragma once

class CreamCheese
{
private:
	double cream_cheese_oz{ 0 };

	CreamCheese() = default;
	double convert_to_grams();

public:
	CreamCheese(double cream_cheese) : cream_cheese_oz(cream_cheese)
	{
		cream_cheese_oz = convert_to_grams();
	}
};

