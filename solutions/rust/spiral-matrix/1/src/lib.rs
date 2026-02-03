enum Direction {
    Right, Down, Left, Up
}
pub fn spiral_matrix(size: u32) -> Vec<Vec<u32>> {
    if size == 0 {return vec![]}
    let mut matrix = vec![vec![0; size as usize]; size as usize];
    let mut direction = Direction::Right;
    let mut last_col_right = size as isize - 1;
    let mut last_row_down = size as isize - 1;
    let mut last_col_left = 0;
    let mut last_row_up = 1;
    let mut current_row: isize = 0;
    let mut current_col: isize = 0;
    for i in 1..=size*size {
        matrix[current_row as usize][current_col as usize] = i;
        match direction {
            Direction::Right=>{
                if current_col == last_col_right {
                    direction = Direction::Down;
                    current_row += 1;
                    last_col_right -= 1;
                } else {
                    current_col += 1;
                }
            }
            Direction::Down=>{
                if current_row == last_row_down {
                    direction = Direction::Left;
                    current_col -= 1;
                    last_row_down -= 1;
                } else {
                    current_row += 1;
                }
            }
            Direction::Left=>{
                if current_col == last_col_left {
                    direction = Direction::Up;
                    current_row -= 1;
                    last_col_left += 1;
                } else {
                    current_col -= 1;
                }
            }
            Direction::Up=>{
                if current_row == last_row_up {
                    direction = Direction::Right;
                    current_col += 1;
                    last_row_up += 1;
                } else {
                    current_row -= 1;
                }
            }
        }
    }
    matrix
}
