#include "VanillaExtract.h"

double VanillaExtract::convert_to_grams()
{
    constexpr double grams{ 4.2 };

    const double conversion{ grams * vanilla_extract_ts };

    return conversion;
}
