pub fn is_armstrong_number(num: u32) -> bool {
    let s = num.to_string();
    let n:u32 = s.len() as u32;
    let t: u32 = s.as_bytes().iter().map(|&c| ((c-b'0') as u32).pow(n)).sum();
    t == num
}
