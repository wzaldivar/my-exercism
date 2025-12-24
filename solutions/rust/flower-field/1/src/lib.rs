use std::collections::VecDeque;

pub fn annotate(garden: &[&str]) -> Vec<String> {
    let mut queue: VecDeque<(isize, isize)> = VecDeque::new();

    let directions: [(isize, isize); 8] = [
        (-1, -1),
        (-1, 0),
        (-1, 1),
        (0, -1),
        (0, 1),
        (1, -1),
        (1, 0),
        (1, 1),
    ];

    let mut field: Vec<Vec<i8>> = garden
        .iter()
        .enumerate()
        .map(|(row, line)| {
            line.chars()
                .enumerate()
                .map(|(col, c)| match c {
                    '*' => {
                        queue.push_back((row as isize, col as isize));
                        -1
                    }
                    _ => 0,
                })
                .collect()
        })
        .collect();

    let rows = field.len() as isize;

    if rows == 0 {
        return Vec::new();
    }

    let cols = field.first().unwrap().len() as isize;

    while let Some((row, col)) = queue.pop_front() {
        directions.iter().for_each(|(dr, dc)| {
            let upd_row = row + dr;
            let upd_col = col + dc;
            if 0 <= upd_row && upd_row < rows && 0 <= upd_col && upd_col < cols {
                if field[upd_row as usize][upd_col as usize] >= 0 {
                    field[upd_row as usize][upd_col as usize] += 1;
                }
            }
        })
    }

    field
        .iter()
        .map(|line| {
            line.iter()
                .map(|c| match c {
                    0 => ' ',
                    -1 => '*',
                    _ => char::from_digit(*c as u32, 10).unwrap(),
                })
                .collect()
        })
        .collect()
}
