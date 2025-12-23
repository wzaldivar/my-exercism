use std::collections::HashSet;

pub fn anagrams_for<'a>(word: &str, possible_anagrams: &[&'a str]) -> HashSet<&'a str> {
    let lowercase_word = word.to_lowercase();

    let normalize = |s: &String| -> Vec<char>{
        let mut chars: Vec<char> = s.chars().collect();
        chars.sort_unstable();
        chars
    };

    let normalized_word = normalize(&lowercase_word);

    let mut result: HashSet<&str> = HashSet::new();

    for possible_anagram in possible_anagrams {
        let lowercase_anagram = possible_anagram.to_lowercase();
        if lowercase_anagram != lowercase_word && normalize(&lowercase_anagram) == normalized_word {
            result.insert(possible_anagram);
        }
    }

    result
}
