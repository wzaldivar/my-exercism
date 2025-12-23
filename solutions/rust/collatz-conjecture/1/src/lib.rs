pub fn collatz(n: u64) -> Option<u64> {
    let mut n = n;

    if n == 0 {
        return None;
    }

    let mut counter: u64 = 0;

    loop {
        if n == 1 {
            break;
        }
        if n % 2 == 0 {
            n /= 2;
        } else {
            n = n * 3 + 1;
        }

        counter += 1;
    }
    Option::from(counter)
}
