pub fn annotate(minefield: &[&str]) -> Vec<String> {
    let n = minefield.len(); // Number of rows
    if n == 0 {
        return vec![];
    }
    let m = minefield[0].len(); // Number of columns

    // Convert the minefield into a mutable `Vec<Vec<u8>>`
    let mut field: Vec<Vec<u8>> = minefield.iter().map(|row| row.as_bytes().to_vec()).collect();

    // Helper function to check boundaries and apply changes
    let apply = |field: &mut Vec<Vec<u8>>, i: isize, j: isize| {
        if i >= 0 && i < n as isize && j >= 0 && j < m as isize {
            let i = i as usize;
            let j = j as usize;

            if field[i][j] == b' ' {
                field[i][j] = b'1';
            } else if field[i][j] != b'*' {
                field[i][j] += 1;
            }
        }
    };

    // Iterate through the minefield
    for i in 0..n {
        for j in 0..m {
            if field[i][j] == b'*' {
                // Apply increments to all neighboring cells
                for di in -1..=1 {
                    for dj in -1..=1 {
                        if !(di == 0 && dj == 0) {
                            apply(&mut field, i as isize + di, j as isize + dj);
                        }
                    }
                }
            }
        }
    }

    // Convert back to a `Vec<String>` for the result
    field
        .into_iter()
        .map(|row| String::from_utf8(row).unwrap())
        .collect()
}
