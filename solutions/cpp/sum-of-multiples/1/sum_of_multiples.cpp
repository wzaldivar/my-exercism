#include "sum_of_multiples.h"

namespace sum_of_multiples
{
    int to(const std::vector<int> &base, int level)
    {
        if (level <= 1 || base.empty())
        {
            return 0;
        }

        int result = 0;

        for (int x : base)
        {
            int n = (level - 1) / x;
            result += n * (n + 1) * x / 2;
        }

        return result;
    }
} // namespace sum_of_multiples
