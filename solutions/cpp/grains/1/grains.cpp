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
        return pow(2.0L, 64) - 1;
    }
} // namespace grains
