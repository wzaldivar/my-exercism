use crate::Classification::{Abundant, Deficient, Perfect};
use std::collections::HashSet;

#[derive(Debug, PartialEq, Eq)]
pub enum Classification {
    Abundant,
    Perfect,
    Deficient,
}

pub fn classify(num: u64) -> Option<Classification> {
    if num == 0 {
        return None;
    }

    let mut factors: HashSet<u64> = HashSet::new();

    if num > 1 {
        factors.insert(1);
    }

    for i in (2..).take_while(|&x| x * x <= num) {
        if num % i == 0 {
            factors.insert(i);
            factors.insert(num / i);
        }
    }

    let s: u64 = factors.iter().sum();

    if s == num {
        return Some(Perfect);
    }

    if s > num {
        return Some(Abundant);
    }

    Some(Deficient)
}
