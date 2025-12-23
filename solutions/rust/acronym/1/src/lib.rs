pub fn abbreviate(phrase: &str) -> String {
    let mut append = true;
    let mut result = String::new();
    let mut prev_lowercase = false;

    phrase.chars().for_each(|c| {
        if c.is_alphabetic() {
            if append || c.is_uppercase() && prev_lowercase {
                result.push(c);
                append = false;
            }
            prev_lowercase = c.is_lowercase();
        } else if c != '\'' {
            append = true;
        }
    });

    result.to_uppercase()
}
