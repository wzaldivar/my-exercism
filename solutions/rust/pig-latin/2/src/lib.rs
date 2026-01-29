pub fn translate(input: &str) -> String {
    input
        .split_whitespace()
        .map(translate_word)
        .collect::<Vec<String>>()
        .join(" ")
}

fn is_vowel(c: char) -> bool {
    matches!(c, 'a' | 'e' | 'i' | 'o' | 'u')
}

fn translate_word(word: &str) -> String {
    let chars: Vec<char> = word.chars().collect();

    if is_vowel(chars[0]) || word.starts_with("xr") || word.starts_with("yt") {
        return format!("{}ay", word);
    }

    let mut idx = 0;
    let mut head: &str = "";
    let mut tail: &str = "";

    while idx < chars.len() {
        if is_vowel(chars[idx]) {
            (head, tail) = word.split_at(idx);
            break;
        }

        if chars[idx] == 'q' && idx + 1 < chars.len() && chars[idx + 1] == 'u' {
            idx += 2;
            (head, tail) = word.split_at(idx);
            break;
        }

        if chars[idx] == 'y' && idx > 0 {
            (head, tail) = word.split_at(idx);
            break;
        }

        idx += 1;
    }

    format!("{}{}ay", tail, head).to_string()
}
