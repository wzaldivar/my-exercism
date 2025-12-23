#include "prime_factors.h"
#include <cmath>

namespace prime_factors
{
    std::vector<int> primes(int limit)
    {
        if (limit < 2)
        {
            return {};
        }

        if (limit == 2)
        {
            return {2};
        }

        int n = limit / 2;
        std::vector<bool> sieve(n, true);
        std::vector<int> result{2};

        for (int i = 0; i < n; ++i)
        {
            if (sieve[i])
            {
                int x = 2 * i + 3;
                result.push_back(x);
                int y = 3 * x;
                int j = (y - 3) / 2;
                while (j < n)
                {
                    sieve[j] = false;
                    y += 2 * x;
                    j = (y - 3) / 2;
                }
            }
        }

        return result;
    }

    std::vector<int> of(int n)
    {
        std::vector<int> p = primes(n);

        std::vector<int> result;

        for (int i : p)
        {
            if (n == 1)
            {
                break;
            }
            while (n % i == 0)
            {
                result.push_back(i);
                n = n / i;
            }
        }

        return result;
    }
} // namespace prime_factors
