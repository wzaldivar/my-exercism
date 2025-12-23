fn sieve(n: usize) -> Vec<u64> {
    if n < 2 {
        return vec![];
    }
    let mut sieve = vec![true; n + 1];
    sieve[0] = false;
    sieve[1] = false;
    let mut primes: Vec<u64> = Vec::with_capacity(n + 1);
    for i in 2..n + 1 {
        if sieve[i] {
            let mut j = i * i;
            while j < n + 1 {
                sieve[j] = false;
                j += i;
            }
        }
    }
    for i in 2..n + 1 {
        if sieve[i] {
            primes.push(i as u64);
        }
    }
    primes
}

pub fn factors(n: u64) -> Vec<u64> {
    let primes = sieve((n as f64).sqrt().ceil() as usize);
    let mut result: Vec<u64> = vec![];
    let mut n: u64 = n;
    for prime in primes {
        if n <= 1 {
            break;
        }
        while n % prime == 0 {
            n /= prime;
            result.push(prime);
        }
    }
    if n > 1 {
        result.push(n);
    }
    result
}
