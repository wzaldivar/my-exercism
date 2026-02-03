use num_traits::Zero;
use std::iter::Sum;
use std::ops::Sub;

pub struct Triangle<T: Zero + PartialOrd + Sub + Copy + Sum<T>> {
    sides: [T; 3],
}

impl<T: Zero + PartialOrd + Sub + Copy + Sum<T>> Triangle<T> {
    pub fn build(sides: [T; 3]) -> Option<Triangle<T>>
    where
        <T as Sub>::Output: PartialOrd<T>,
    {
        if sides.iter().any(|side| side.is_zero()) {
            return None;
        }

        let sides_sum: T = sides.iter().cloned().sum();

        if sides.iter().any(|&side| sides_sum - side <= side) {
            return None;
        }

        Some(Triangle { sides })
    }

    pub fn is_equilateral(&self) -> bool {
        self.sides[0] == self.sides[1] && self.sides[1] == self.sides[2]
    }

    pub fn is_scalene(&self) -> bool {
        !self.is_isosceles()
    }

    pub fn is_isosceles(&self) -> bool {
        self.sides[0] == self.sides[1]
            || self.sides[0] == self.sides[2]
            || self.sides[1] == self.sides[2]
    }
}
