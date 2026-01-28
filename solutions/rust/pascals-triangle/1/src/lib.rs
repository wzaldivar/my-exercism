pub struct PascalsTriangle {
    count: usize
}

impl PascalsTriangle {
    pub fn new(row_count: u32) -> Self {
        PascalsTriangle {
            count: row_count as usize
        }
    }

    pub fn rows(&self) -> Vec<Vec<u32>> {
        let mut result: Vec<Vec<u32>> = vec![];

        for row in 0..self.count {
            let mut row_values = Vec::with_capacity(row + 1);
            row_values.push(1);

            if row > 0 {
                for col in 1..result[row - 1].len() {
                    row_values.push(result[row - 1][col - 1] + result[row - 1][col]);
                }

                row_values.push(1);
            }

            result.push(row_values);
        }

        result
    }
}
