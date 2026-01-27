/// Determines whether the supplied string is a valid ISBN number
pub fn is_valid_isbn(isbn: &str) -> bool {
    let mut digits: Vec<u32> = Vec::new();
    for c in isbn.chars() {
        if !c.is_numeric() && c != '-' && c.to_ascii_lowercase() != 'x'{
            return false;
        }
        if c.is_numeric() {
            digits.push(c.to_digit(10).unwrap());
        }
        if c.to_ascii_lowercase() == 'x' {
            digits.push(10);
        }
    }

    if digits.len() != 10 {
        return false;
    }

    if digits[0..9].iter().any(|&d| d == 10) {
        return false;
    }

    let mut sum = 0;
    digits.iter().enumerate().for_each(|(i, &digit)| {
        sum += digit * (10 - i as u32);
    });

    sum % 11 == 0
}
