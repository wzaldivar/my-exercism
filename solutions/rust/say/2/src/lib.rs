use std::mem::discriminant;

fn encode_1(n: u64) -> String {
    match n {
        1 => "one".to_string(),
        2 => "two".to_string(),
        3 => "three".to_string(),
        4 => "four".to_string(),
        5 => "five".to_string(),
        6 => "six".to_string(),
        7 => "seven".to_string(),
        8 => "eight".to_string(),
        9 => "nine".to_string(),
        _ => "".to_string(),
    }
}

fn encode_10(n: u64) -> String {
    match n {
        10 => "ten".to_string(),
        11 => "eleven".to_string(),
        12 => "twelve".to_string(),
        13 => "thirteen".to_string(),
        14 => "fourteen".to_string(),
        15 => "fifteen".to_string(),
        16 => "sixteen".to_string(),
        17 => "seventeen".to_string(),
        18 => "eighteen".to_string(),
        19 => "nineteen".to_string(),
        20 => "twenty".to_string(),
        (21..=29) => format!("twenty-{}", encode_1(n % 10)),
        30 => "thirty".to_string(),
        (31..=39) => format!("thirty-{}", encode_1(n % 10)),
        40 => "forty".to_string(),
        (41..=49) => format!("forty-{}", encode_1(n % 10)),
        50 => "fifty".to_string(),
        (51..=59) => format!("fifty-{}", encode_1(n % 10)),
        60 => "sixty".to_string(),
        (61..=69) => format!("sixty-{}", encode_1(n % 10)),
        70 => "seventy".to_string(),
        (71..=79) => format!("seventy-{}", encode_1(n % 10)),
        80 => "eighty".to_string(),
        (81..=89) => format!("eighty-{}", encode_1(n % 10)),
        90 => "ninety".to_string(),
        (91..=99) => format!("ninety-{}", encode_1(n % 10)),
        _ => encode_1(n),
    }
}
fn encode_100(n: u64) -> String {
    let hundreds = n / 100;
    let remainder = n % 100;

    if hundreds == 0 {
        return encode_10(remainder);
    }

    let mut result = format!("{} hundred", encode_1(hundreds));

    if remainder > 0 {
        result.push(' ');
        result.push_str(&encode_10(remainder));
    }

    result
}

pub fn encode(n: u64) -> String {
    if n == 0 {
        return "zero".to_string();
    }

    let mut remainder = n;
    let mut divisor:u64 = 1_000_000_000_000_000_000;
    let mut thousands: u64;

    let mut result = String::new();

    while divisor > 0 {
        thousands = remainder / divisor;
        remainder = remainder % divisor;
    if thousands > 0 {
        if !result.is_empty(){
            result.push(' ');
        }
        match divisor {
            1_000_000_000_000_000_000 => result.push_str(format!("{} quintillion", encode_100(thousands)).as_str()),
            1_000_000_000_000_000 => result.push_str(format!("{} quadrillion", encode_100(thousands)).as_str()),
            1_000_000_000_000 => result.push_str(format!("{} trillion", encode_100(thousands)).as_str()),
            1_000_000_000 => result.push_str(format!("{} billion", encode_100(thousands)).as_str()),
            1_000_000 => result.push_str(format!("{} million", encode_100(thousands)).as_str()),
            1_000 => result.push_str(format!("{} thousand", encode_100(thousands)).as_str()),
            _ => result.push_str(encode_100(thousands).as_str()),
        }
    }
    divisor /= 1_000;
    }
    result
}
