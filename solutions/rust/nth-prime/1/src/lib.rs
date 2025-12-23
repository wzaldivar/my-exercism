fn sieve(n: usize, primes: &mut Vec<u32>) {
    let chunk_size = 1000;
    let mut base: u32 = 0;

    while primes.len() <= n {
        let mut sieve_array = vec![true; chunk_size];

        if base == 0 {
            if n >= 1 {
                primes.push(2);
            }
            sieve_array[0] = false;
            sieve_array[1] = false;
        }

        for &prime in primes.iter() {
            let mut i = (prime - (base % prime)) % prime;

            while i < chunk_size as u32 {
                sieve_array[i as usize] = false;
                i += prime;
            }
        }

        for i in 0..chunk_size {
            if sieve_array[i] {
                let prime = base + i as u32;
                primes.push(prime);

                let mut j = i + prime as usize;
                while j < chunk_size {
                    sieve_array[j] = false;
                    j += prime as usize;
                }

                if primes.len() > n {
                    return;
                }
            }
        }

        base += chunk_size as u32;
    }
}

pub fn nth(n: u32) -> u32 {
    let mut primes: Vec<u32> = Vec::with_capacity((n + 1) as usize);
    sieve(n as usize, &mut primes);
    primes[n as usize]
}
