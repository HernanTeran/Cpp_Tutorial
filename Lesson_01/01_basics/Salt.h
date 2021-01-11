#pragma once

class Salt
{
private:
	double salt_ts{ 0 };

	Salt() = default;
	double convert_to_grams();

public:
	Salt(double salt) : salt_ts(salt)
	{
		salt_ts = convert_to_grams();
	}
};
