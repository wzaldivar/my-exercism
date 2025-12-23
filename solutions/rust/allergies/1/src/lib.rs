use crate::Allergen::{Cats, Chocolate, Eggs, Peanuts, Pollen, Shellfish, Strawberries, Tomatoes};

pub struct Allergies {
    allergens: Vec<Allergen>,
}

#[derive(Debug, PartialEq, Eq, Clone, Copy)]
pub enum Allergen {
    Eggs,
    Peanuts,
    Shellfish,
    Strawberries,
    Tomatoes,
    Chocolate,
    Pollen,
    Cats,
}

fn from_number(index: u32) -> Option<Allergen> {
    match index {
        1 => Some(Eggs),
        2 => Some(Peanuts),
        4 => Some(Shellfish),
        8 => Some(Strawberries),
        16 => Some(Tomatoes),
        32 => Some(Chocolate),
        64 => Some(Pollen),
        128 => Some(Cats),
        _ => None,
    }
}

impl Allergies {
    pub fn new(score: u32) -> Self {
        let mut allergens = Vec::new();
        let mut index: u32 = 1;
        while index <= 128 {
            let allergen = from_number(score & index);
            if allergen.is_some() {
                allergens.push(allergen.unwrap());
            }
            index <<= 1;
        }
        Allergies { allergens }
    }

    pub fn is_allergic_to(&self, allergen: &Allergen) -> bool {
        self.allergens.contains(allergen)
    }

    pub fn allergies(&self) -> Vec<Allergen> {
        self.allergens.clone()
    }
}
