#include "SourCream.h"

double SourCream::convert_to_grams()
{
    constexpr double grams{ 200 };

    const double conversion{ grams * sour_cream_cups };

    return conversion;
}
