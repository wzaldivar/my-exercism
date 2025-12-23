pub fn build_proverb(list: &[&str]) -> String {
    let n = list.len();
    if n == 0 {
        return String::new();
    }

    let mut proverb = String::new();
    for i in 1..n {
        if i > 1 {
            proverb += "\n";
        }
        proverb += &format!("For want of a {} the {} was lost.", list[i - 1], list[i]);
    }
    if n > 1 {
        proverb += "\n";
    }
    proverb += &format!("And all for the want of a {}.", list[0]);
    proverb
}
