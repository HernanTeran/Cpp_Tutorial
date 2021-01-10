#pragma once

class Sugar
{
private:
	int white_sugar_cups{ 0 };

	Sugar() = default;
	int convert_to_grams();

public:
	Sugar(int white_sugar) : white_sugar_cups(white_sugar)
	{
		white_sugar_cups = convert_to_grams();
	}
};
