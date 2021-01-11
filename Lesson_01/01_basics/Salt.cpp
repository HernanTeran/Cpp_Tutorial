#include "Salt.h"

double Salt::convert_to_grams()
{
    constexpr double grams{ 4.2 };

    const double conversion{ grams * salt_ts };

    return conversion;
}
