use std::collections::HashMap;

pub fn plants(diagram: &str, student: &str) -> Vec<&'static str> {
    let seeds: HashMap<char, &str> = HashMap::from([
        ('G', "grass"),
        ('C', "clover"),
        ('R', "radishes"),
        ('V', "violets"),
    ]);

    let students = [
        "Alice", "Bob", "Charlie", "David", "Eve", "Fred", "Ginny", "Harriet", "Ileana", "Joseph",
        "Kincaid", "Larry",
    ];

    let index: usize = students.iter().position(|&s| s == student).unwrap();

    let lines: Vec<&str> = diagram.split('\n').collect();

    let mut student_seeds: Vec<char> = vec![];

    for &line in lines.iter() {
        student_seeds.push(line.chars().nth(index * 2).unwrap());
        student_seeds.push(line.chars().nth(index * 2 + 1).unwrap());
    }

    student_seeds.iter().map(|c| seeds[c]).collect()
}
