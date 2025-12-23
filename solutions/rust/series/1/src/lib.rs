pub fn series(digits: &str, len: usize) -> Vec<String> {
    let n = digits.len();

    if n == 0 || n < len || len == 0 {
        return Vec::new();
    }

    (0..=n - len)
        .map(|i| digits[i..i + len].to_string())
        .collect()
}
