/// Check a Luhn checksum.
pub fn is_valid(code: &str) -> bool {
    if code.as_bytes().iter().any(|&c| c != b' ' && !(b'0'..=b'9').contains(&c)) {
        return false;
    }

    let mut digits: Vec<u8> = code
        .as_bytes()
        .iter()
        .filter(|&&c| (b'0'..=b'9').contains(&c))
        .map(|&c| c - b'0')
        .collect();

    let n = digits.len();

    if n <= 1 {
        return false;
    }

    for i in (0..n - 1).rev().step_by(2) {
        let doubled = digits[i] * 2;
        digits[i] = if doubled > 9 { doubled - 9 } else { doubled };
    }

    let sum: u64 = digits.iter().map(|&digit| digit as u64).sum();

    sum % 10 == 0
}
