#include "rating.h"

const string rating::getRating() const
{
    if (1.0 <= getRatingNum() && getRatingNum() <= 1.5)
        return "Below";
    else if (1.5 < getRatingNum() && getRatingNum() <= 2.5)
        return "Same";
    else if (2.5 < getRatingNum() && getRatingNum() <= 3.0)
        return "Above";
    else
        return "Unknown";
}
