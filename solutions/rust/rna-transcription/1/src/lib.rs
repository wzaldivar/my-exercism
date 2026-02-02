#[derive(Debug, PartialEq, Eq)]
pub struct Dna {
    strand: String,
}

#[derive(Debug, PartialEq, Eq)]
pub struct Rna {
    pub strand: String,
}

impl Dna {
    pub fn new(dna: &str) -> Result<Dna, usize> {
        let error_index :Option<usize> = dna.chars().position(|c| !"ACGT".contains(c));

        if let Some(index) = error_index {
            return Err(index);
        }

        Ok(Dna { strand: dna.to_string() })
    }

    pub fn into_rna(self) -> Rna {
        Rna::new(&self.complement()).unwrap()
    }

    fn complement(&self) -> String {
        self.strand.chars().map(|c| match c {
            'G' => 'C',
            'C' => 'G',
            'T' => 'A',
            'A' => 'U',
            _ => panic!("Invalid nucleotide")
        }).collect()
    }
}

impl Rna {
    pub fn new(rna: &str) -> Result<Rna, usize> {
        let error_index :Option<usize> = rna.chars().position(|c| !"ACGU".contains(c));

        if let Some(index) = error_index {
            return Err(index);
        }

        Ok(Rna{ strand: rna.to_string()})
    }
}
