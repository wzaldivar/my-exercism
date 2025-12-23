pub fn egg_count(display_value: u32) -> usize {
    let mut n: u32 = display_value;
    let mut count: usize = 0;

    while n > 0 {
        count += (n % 2) as usize;
        n /= 2;
    }

    count
}
