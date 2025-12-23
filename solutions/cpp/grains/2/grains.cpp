#include "grains.h"

#include <cmath>

namespace grains
{
    unsigned long long square(int n)
    {
        return pow(2.0L, n - 1);
    }

    unsigned long long total()
    {
        return pow(2.0L, 63) - 1 + pow(2.0L, 63);
    }
} // namespace grains
