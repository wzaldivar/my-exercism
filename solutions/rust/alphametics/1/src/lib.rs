use itertools::Itertools;
use std::collections::{BTreeSet, HashMap, HashSet};

fn str_to_num(s: &str, m: &HashMap<char, u8>) -> u64 {
    s.chars()
        .map(|c| *m.get(&c).unwrap() as u64)
        .fold(0, |acc, d| acc * 10 + d)
}

pub fn solve(input: &str) -> Option<HashMap<char, u8>> {
    let parts: Vec<&str> = input.split("==").map(|s| s.trim()).collect();

    if parts.len() != 2 {
        return None;
    }

    let expected: &str = parts[1];
    let elements: Vec<&str> = parts[0].split("+").map(|s| s.trim()).collect();

    let keys: Vec<char> = input
        .chars()
        .filter(|c| ('A'..='Z').contains(c))
        .collect::<BTreeSet<_>>()
        .into_iter()
        .collect();

    if keys.len() > 10 {
        return None;
    }

    let not_zero: HashSet<char> = std::iter::once(expected)
        .chain(elements.iter().copied())
        .filter_map(|s| s.chars().next())
        .collect();

    let mut result: Option<HashMap<char, u8>> = None;

    for digits in (0u8..=9).permutations(keys.len()) {
        let candidate: HashMap<char, u8> = keys.iter().copied().zip(digits).collect();

        if not_zero.iter().any(|k| candidate[k] == 0) {
            continue;
        }

        let expected_num: u64 = str_to_num(expected, &candidate);
        let calculated_num: u64 = elements.iter().map(|e| str_to_num(e, &candidate)).sum();

        if expected_num == calculated_num {
            if result.is_none() {
                result = Some(candidate);
            } else {
                return None;
            }
        }
    }

    result
}
