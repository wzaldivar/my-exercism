use std::collections::HashMap;

pub fn brackets_are_balanced(string: &str) -> bool {
    let mut stack: Vec<u8> = Vec::new();
    let close_map: HashMap<u8, u8> = HashMap::from([(b')', b'('), (b']', b'['), (b'}', b'{')]);
    for c in string.as_bytes().iter() {
        match c {
            b'(' | b'[' | b'{' => stack.push(*c),
            b')' | b']' | b'}' => {
                let last = stack.pop();
                if last.is_none() || last.unwrap() != close_map[c] {
                    return false;
                }
            }
            _ => continue,
        }
    }
    stack.is_empty()
}
