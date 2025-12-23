pub fn sum_of_multiples(limit: u32, factors: &[u32]) -> u32 {
    let mut sieve: Vec<u32> = vec![0; limit as usize];
    for factor in factors.iter().filter(|f| **f > 0).collect::<Vec<&u32>>() {
        let mut i: u32 = *factor;
        while i < limit {
            sieve[i as usize] = i;
            i += *factor;
        }
    }
    sieve.iter().sum()
}
