#include "sum_of_multiples.h"
#include <vector>

namespace sum_of_multiples
{
    int to(const std::vector<int> &base, int level)
    {
        if (level <= 1 || base.empty())
        {
            return 0;
        }

        std::vector<bool> sieve(level, false);

        for (int b : base)
        {
            int i = b;
            while (i < level)
            {
                sieve[i] = true;
                i += b;
            }
        }

        int result = 0;

        for (int i = 1; i < level; ++i)
        {
            if (sieve[i])
            {
                result += i;
            }
        }

        return result;
    }
} // namespace sum_of_multiples
