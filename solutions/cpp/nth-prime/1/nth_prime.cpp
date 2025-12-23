#include "nth_prime.h"

#include <stdexcept>
#include <vector>

namespace nth_prime {
    typedef unsigned long prime_t;
    typedef std::vector<prime_t> primes_t;

    primes_t primes;

    prime_t k;

    prime_t sieve_at(primes_t::size_type i) {
        return 1000 * k + 2 * i + 1;
    }

    primes_t::size_type sieve_index(prime_t n) {
        return (n - 1000 * k - 1) / 2;
    }

    primes_t::size_type first_index(prime_t p) {
        prime_t l = 1000 * k / p + 1;
        if (l % 2 == 0) {
            ++l;
        }

        return sieve_index(p * l); 
    }

    void do_sieve(){
        bool sieve[500];

        for (primes_t::size_type i = 0; i < 500; ++i){
            sieve[i] = !(k==0 && i ==0);
        }

        for (primes_t::iterator it = primes.begin() + 1; it != primes.end(); ++it){
            prime_t p = *it;
            if ((p * p) < 1000 * ( k + 1 )) {
                primes_t::size_type j = first_index(p);
                while (j < 500)
                {
                    sieve[j] = false;
                    j = sieve_index(sieve_at(j)+2*p);
                }
            } else {
                break;
            }
        }

        for (primes_t::size_type i = 0; i < 500; ++i){
            if (sieve[i]){
                prime_t p = sieve_at(i);
                primes.push_back(p);
                primes_t::size_type j = sieve_index(sieve_at(i)+2*p);
                while (j < 500)
                {
                    sieve[j] = false;
                    j = sieve_index(sieve_at(j)+2*p);
                }
            }
        } 
    }

    unsigned long nth(const int n) {
        if (n < 1){
            throw std::domain_error("invalid n");
        }

        if (primes.empty()){
            primes.push_back(2);
            k = 0;
        }

        while (primes.size() < static_cast<primes_t::size_type>(n))
        {
            do_sieve();
            k++;
        }
        

        return primes[n-1];
    }
}  // namespace nth_prime
