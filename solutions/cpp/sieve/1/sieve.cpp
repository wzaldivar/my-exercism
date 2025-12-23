#include "sieve.h"

namespace sieve
{
    typedef int prime_t;
    typedef std::vector<prime_t> primes_t;

    primes_t m_primes;

    prime_t k;

    prime_t sieve_at(primes_t::size_type i)
    {
        return 1000 * k + 2 * i + 1;
    }

    primes_t::size_type sieve_index(prime_t n)
    {
        return (n - 1000 * k - 1) / 2;
    }

    primes_t::size_type first_index(prime_t p)
    {
        prime_t l = 1000 * k / p + 1;
        if (l % 2 == 0)
        {
            ++l;
        }

        return sieve_index(p * l);
    }

    void do_sieve()
    {
        bool sieve[500];

        for (primes_t::size_type i = 0; i < 500; ++i)
        {
            sieve[i] = !(k == 0 && i == 0);
        }

        for (primes_t::iterator it = m_primes.begin() + 1; it != m_primes.end(); ++it)
        {
            prime_t p = *it;
            if ((p * p) < 1000 * (k + 1))
            {
                primes_t::size_type j = first_index(p);
                while (j < 500)
                {
                    sieve[j] = false;
                    j = sieve_index(sieve_at(j) + 2 * p);
                }
            }
            else
            {
                break;
            }
        }

        for (primes_t::size_type i = 0; i < 500; ++i)
        {
            if (sieve[i])
            {
                prime_t p = sieve_at(i);
                m_primes.push_back(p);
                primes_t::size_type j = sieve_index(sieve_at(i) + 2 * p);
                while (j < 500)
                {
                    sieve[j] = false;
                    j = sieve_index(sieve_at(j) + 2 * p);
                }
            }
        }
    }

    std::vector<int> primes(int limit)
    {
        std::vector<int> result;

        if (m_primes.empty())
        {
            m_primes.push_back(2);
            k = 0;
        }

        while (m_primes.back() <= limit)
        {
            do_sieve();
            k++;
        }

        for (primes_t::iterator it = m_primes.begin(); it != m_primes.end(); ++it)
        {
            if (*it <= limit)
            {
                result.push_back(*it);
            }
            else
            {
                break;
            }
        }

        return result;
    }
} // namespace sieve
