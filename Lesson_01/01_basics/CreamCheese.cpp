#include "CreamCheese.h"

double CreamCheese::convert_to_grams()
{
    constexpr double grams{ 28.35 };

    const double conversion{ grams * cream_cheese_oz };

    return conversion;
}
