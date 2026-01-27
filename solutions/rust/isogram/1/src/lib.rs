use std::collections::HashSet;

pub fn check(candidate: &str) -> bool {
    let mut seen: HashSet<char> = HashSet::new();
    for c in candidate.chars() {
        if c.is_ascii_alphabetic() {
            let current = c.to_ascii_lowercase();
            if seen.contains(&current) {
                return false;
            }
            seen.insert(current);
        }
    }
    true
}
