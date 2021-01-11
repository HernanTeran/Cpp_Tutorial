#pragma once

class SourCream
{
private:
	double sour_cream_cups{ 0 };

	SourCream() = default;
	double convert_to_grams();

public:
	SourCream(double sour_cream) : sour_cream_cups(sour_cream)
	{
		sour_cream_cups = convert_to_grams();
	}
};

