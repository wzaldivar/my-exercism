#include "trinary.h"

#include <cmath>

namespace trinary
{
    unsigned int to_decimal(std::string trinary)
    {
        size_t n = trinary.length();
        size_t i = n - 1;

        unsigned int d = 0;

        while (i < n)
        {
            char c = trinary[i];
            if (c < '0' || c > '2')
            {
                return 0;
            }
            d += (c - '0') * pow(3, n - i - 1);
            --i;
        }

        return d;
    }
} // namespace trinary
