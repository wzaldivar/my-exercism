use std::collections::HashMap;

pub fn find_saddle_points(input: &[Vec<u64>]) -> Vec<(usize, usize)> {
    let mut output = vec![];

    let mut max_cols : HashMap<usize, Vec<usize>> = HashMap::new();
    let mut cols: HashMap<usize, Vec<u64>> = HashMap::new();

    for (row, row_data) in input.iter().enumerate() {
        if row_data.is_empty() { continue; }
        let max_row_data = row_data.iter().max().unwrap();
        for (col, col_data) in row_data.iter().enumerate() {
            cols.entry(col).or_default().push(*col_data);
            if *col_data == *max_row_data {
                max_cols.entry(row).or_default().push(col);
            }
        }
    }


    cols.iter().for_each(|(col, col_data)| {
        let min_col_data = col_data.iter().min().unwrap();
        col_data.iter().enumerate().for_each(|(row, val)| {
            if *val == *min_col_data && max_cols.entry(row).or_default().contains(col) {
                output.push((row, *col));
            }
        });
    });

    output
}

