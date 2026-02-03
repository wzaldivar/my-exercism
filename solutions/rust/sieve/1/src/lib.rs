pub fn primes_up_to(upper_bound: u64) -> Vec<u64> {
    if upper_bound < 2 {
        return vec![];
    }
    let mut primes = Vec::new();
    let mut sieve_of_eratosthenes = vec![true; upper_bound as usize];
    sieve_of_eratosthenes[0] = false;
    for index in 0..upper_bound as usize {
        if sieve_of_eratosthenes[index] {
            let value = index as u64 + 1;
            primes.push(value);
            for multiple in (index..upper_bound as usize).step_by(value as usize) {
                sieve_of_eratosthenes[multiple] = false;
            }
        }
    }
    primes
}
