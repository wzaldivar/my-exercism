pub fn reply(message: &str) -> &str {
    let is_question = message.trim().ends_with('?');
    let is_yell =
        message == message.trim().to_uppercase() && message.chars().any(|c| c.is_alphabetic());
    let is_silence = message.trim().is_empty();

    if is_question && is_yell {
        return "Calm down, I know what I'm doing!";
    }

    if is_question {
        return "Sure.";
    }

    if is_yell {
        return "Whoa, chill out!";
    }

    if is_silence {
        return "Fine. Be that way!";
    }

    "Whatever."
}
