#include "Sugar.h"

int Sugar::convert_to_grams()
{
    constexpr int grams{ 200 };

    const int conversion{ grams * white_sugar_cups };

    return conversion;
}
