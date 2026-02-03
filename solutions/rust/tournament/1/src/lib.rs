use std::cmp::Reverse;
use std::collections::HashMap;

struct Team {
    name: String,
    matches: u32,
    wins: u32,
    draws: u32,
    losses: u32,
    points: u32,
}

impl Team {
    fn new(name: String) -> Self {
        Self {
            name,
            matches: 0,
            wins: 0,
            draws: 0,
            losses: 0,
            points: 0,
        }
    }

    fn add_win(&mut self) {
        self.matches += 1;
        self.wins += 1;
        self.points += 3;
    }

    fn add_draw(&mut self) {
        self.matches += 1;
        self.draws += 1;
        self.points += 1;
    }

    fn add_loss(&mut self) {
        self.matches += 1;
        self.losses += 1;
    }

    fn to_table_row(&self) -> String {
        format!(
            "{:<30} | {:>2} | {:>2} | {:>2} | {:>2} | {:>2}",
            self.name, self.matches, self.wins, self.draws, self.losses, self.points
        )
    }
}

pub fn tally(match_results: &str) -> String {
    let matches = match_results.lines();
    let mut table: HashMap<String, Team> = HashMap::new();
    for match_result in matches {
        let line = match_result.split(';').collect::<Vec<&str>>();
        match line[2] {
            "win" => {
                table
                    .entry(line[0].to_string())
                    .or_insert(Team::new(line[0].to_string()))
                    .add_win();
                table
                    .entry(line[1].to_string())
                    .or_insert(Team::new(line[1].to_string()))
                    .add_loss();
            }
            "draw" => {
                table
                    .entry(line[0].to_string())
                    .or_insert(Team::new(line[0].to_string()))
                    .add_draw();
                table
                    .entry(line[1].to_string())
                    .or_insert(Team::new(line[1].to_string()))
                    .add_draw();
            }
            "loss" => {
                table
                    .entry(line[0].to_string())
                    .or_insert(Team::new(line[0].to_string()))
                    .add_loss();
                table
                    .entry(line[1].to_string())
                    .or_insert(Team::new(line[1].to_string()))
                    .add_win();
            }
            _ => {}
        }
    }
    let mut teams = table.values().collect::<Vec<&Team>>();
    teams.sort_unstable_by_key(|team| (Reverse(team.points), team.name.clone()));

    let mut results: Vec<String> =
        vec!["Team                           | MP |  W |  D |  L |  P".to_string()];
    results.extend(teams.iter().map(|team| team.to_table_row()));
    results.join("\n")
}
