#pragma once
class VanillaExtract
{
private:
	double vanilla_extract_ts{ 0 };

	VanillaExtract() = default;
	double convert_to_grams();

public:
	VanillaExtract(double vanilla_extract) : vanilla_extract_ts(vanilla_extract)
	{
		vanilla_extract_ts = convert_to_grams();
	}
};
