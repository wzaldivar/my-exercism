use std::collections::HashMap;

fn verse(bottles: u32) -> String {
    let numbers: HashMap<u32, &str> = [
        (0, "No"),
        (1, "One"),
        (2, "Two"),
        (3, "Three"),
        (4, "Four"),
        (5, "Five"),
        (6, "Six"),
        (7, "Seven"),
        (8, "Eight"),
        (9, "Nine"),
        (10, "Ten"),
    ]
    .iter()
    .cloned()
    .collect();

    let first_line = format!(
        "{} green bottle{} hanging on the wall,",
        numbers[&bottles],
        if bottles == 1 { "" } else { "s" }
    );
    let third_line = "And if one green bottle should accidentally fall,";
    let fourth_line = format!(
        "There'll be {} green bottle{} hanging on the wall.",
        numbers[&(bottles - 1)].to_lowercase(),
        if bottles - 1 == 1 { "" } else { "s" }
    );

    [
        first_line.clone(),
        first_line,
        third_line.to_string(),
        fourth_line,
    ]
    .join("\n")
}

pub fn recite(start_bottles: u32, take_down: u32) -> String {
    let mut bottles = start_bottles;
    let verses: Vec<String> = (0..take_down)
        .map(|_| {
            let verse = verse(bottles);
            bottles -= 1;
            verse
        })
        .collect();
    verses.join("\n\n")
}
