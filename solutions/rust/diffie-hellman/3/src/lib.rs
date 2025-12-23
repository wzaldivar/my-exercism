use rand::Rng;

fn sieve(n: usize) -> Vec<u64> {
    if n < 2 {
        return vec![];
    }
    let mut sieve: Vec<bool> = vec![true; n];
    sieve[0] = false;
    sieve[1] = false;
    let mut primes_vec: Vec<u64> = Vec::with_capacity(n);
    for i in 2..n {
        if sieve[i] {
            let mut j: usize = i * i;
            while j < n {
                sieve[j] = false;
                j += i;
            }
        }
    }
    for i in 2..n {
        if sieve[i] {
            primes_vec.push(i as u64);
        }
    }
    primes_vec
}

fn mod_exp(mut base: u64, mut exponent: u64, modulus: u64) -> u64 {
    if modulus == 1 {
        return 0;
    }

    let mut result = 1;
    base = base % modulus;

    while exponent > 0 {
        if exponent % 2 == 1 {
            result = result * base % modulus;
        }
        exponent >>= 1;
        base = (base * base) % modulus;
    }

    result
}

pub fn private_key(p: u64) -> u64 {
    let primes: Vec<u64> = sieve(p as usize);
    primes[rand::thread_rng().gen_index(..primes.len())]
}

pub fn public_key(p: u64, g: u64, a: u64) -> u64 {
    mod_exp(g, a, p)
}

pub fn secret(p: u64, b_pub: u64, a: u64) -> u64 {
    mod_exp(b_pub, a, p)
}
