fn encode_char(c: char, count: usize) -> String {
    if count == 1 {
        c.to_string()
    } else {
        format!("{}{}", count, c)
    }
}

pub fn encode(source: &str) -> String {
    let mut encoded = String::new();
    let mut count = 0;
    let mut last: Option<char> = None;
    for c in source.chars() {
        match last {
            Some(l) if l == c => count += 1,
            Some(l) => {
                encoded.push_str(encode_char(l, count).as_str());
                last = Some(c);
                count = 1;
            }
            _ => {
                last = Some(c);
                count = 1;
            }
        }
    }
    if let Some(l) = last {
        encoded.push_str((encode_char(l, count)).as_str());
    }
    encoded
}

pub fn decode(source: &str) -> String {
    let mut decoded = String::new();
    let mut count = 0;
    for c in source.chars() {
        match c {
            '0'..='9' => count = count * 10 + c.to_digit(10).unwrap() as usize,
            _ => {
                if count == 0 {
                    decoded.push_str(c.to_string().as_str());
                } else {
                    decoded.push_str((0..count).map(|_| c).collect::<String>().as_str());
                }
                count = 0;
            }
        }
    }
    decoded
}
