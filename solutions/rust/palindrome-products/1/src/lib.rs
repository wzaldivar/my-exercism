use std::collections::HashSet;

#[derive(Debug, Clone, PartialEq, Eq)]
pub struct Palindrome {
    _value: u64,
    _factors: HashSet<(u64, u64)>,
}

impl Palindrome {
    pub fn new(value: u64) -> Self {
        Self {
            _value: value,
            _factors: HashSet::new(),
        }
    }

    pub fn value(&self) -> u64 {
        self._value
    }

    pub fn into_factors(self) -> HashSet<(u64, u64)> {
        self._factors
    }

    fn add_factors(&mut self, factors: (u64, u64)) {
        self._factors.insert(factors);
    }
}

fn is_palindrome(n: u64) -> bool {
    let digits: Vec<char> = n.to_string().chars().collect();
    digits == digits.iter().rev().cloned().collect::<Vec<char>>()
}

pub fn palindrome_products(min: u64, max: u64) -> Option<(Palindrome, Palindrome)> {
    let mut min_palindrome: Option<Palindrome> = None;
    let mut max_palindrome: Option<Palindrome> = None;

    for i in min..=max {
        for j in i..=max {
            let candidate = i * j;
            match &mut min_palindrome {
                Some(pal) => {
                    if candidate == pal._value {
                        pal.add_factors((i, j));
                    } else if candidate < pal._value && is_palindrome(candidate) {
                        let mut new_pal = Palindrome::new(candidate);
                        new_pal.add_factors((i, j));
                        min_palindrome = Some(new_pal);
                    }
                }
                None => {
                    if is_palindrome(candidate) {
                        let mut pal = Palindrome::new(candidate);
                        pal.add_factors((i, j));
                        min_palindrome = Some(pal);
                    }
                }
            }

            match &mut max_palindrome {
                Some(pal) => {
                    if candidate == pal._value {
                        pal.add_factors((i, j));
                    } else if candidate > pal._value && is_palindrome(candidate) {
                        let mut new_pal = Palindrome::new(candidate);
                        new_pal.add_factors((i, j));
                        max_palindrome = Some(new_pal);
                    }
                }
                None => {
                    if is_palindrome(candidate) {
                        let mut pal = Palindrome::new(candidate);
                        pal.add_factors((i, j));
                        max_palindrome = Some(pal);
                    }
                }
            }
        }
    }

    match (min_palindrome, max_palindrome) {
        (Some(min_p), Some(max_p)) => Some((min_p, max_p)),
        _ => None,
    }
}
