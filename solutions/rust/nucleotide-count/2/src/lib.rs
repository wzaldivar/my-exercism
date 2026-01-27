use std::collections::HashMap;

static VALID_NUCLEOTIDES: [char; 4] = ['A', 'C', 'G', 'T'];

pub fn count(nucleotide: char, dna: &str) -> Result<usize, char> {
    if !VALID_NUCLEOTIDES.contains(&nucleotide) {
        return Err(nucleotide);
    }
    let counts = nucleotide_counts(dna)?;
    Ok(counts.get(&nucleotide).copied().unwrap_or(0))
}

pub fn nucleotide_counts(dna: &str) -> Result<HashMap<char, usize>, char> {
    let mut counts: HashMap<char, usize> = HashMap::new();

    for nucleotide in VALID_NUCLEOTIDES.iter() {
        counts.insert(*nucleotide, 0);
    }

    for nucleotide in dna.chars() {
        if !VALID_NUCLEOTIDES.contains(&nucleotide) {
            return Err(nucleotide);
        }
        counts.entry(nucleotide).and_modify(|count| *count += 1);
    }
    Ok(counts)
}
