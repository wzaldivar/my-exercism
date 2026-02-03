/// Compute the Scrabble score for a word.
pub fn score(word: &str) -> u64 {
    let lower_word = word.to_lowercase();
    let mut score = 0;
    for letter in lower_word.chars() {
        match letter {
            'a' | 'e' | 'i' | 'o' | 'u' | 'l' | 'n' | 'r' | 's' | 't' => score += 1,
            'd' | 'g' => score += 2,
            'b' | 'c' | 'm' | 'p' => score += 3,
            'f' | 'h' | 'v' | 'w' | 'y' => score += 4,
            'k' => score += 5,
            'j' | 'x' => score += 8,
            'q' | 'z' => score += 10,
            _ => {},
        }
    }
    score
}
