#include "nucleotide_count.h"

#include <stdexcept>

namespace nucleotide_count {
    counter::counter(const std::string dna_chain) {
        this->counts['A'] = 0;
        this->counts['T'] = 0;
        this->counts['C'] = 0;
        this->counts['G'] = 0;

        for (char i: dna_chain) {
            if (i == 'A' || i == 'T' || i == 'C' || i == 'G') {
                this->counts[i]++;
            } else {
                throw std::invalid_argument("invalid chain");
            }
        }
    }

    std::map<char, int> counter::nucleotide_counts() const {
        return this->counts;
    }

    int counter::count(const char nucleotide) const {
        if (nucleotide != 'A' && nucleotide != 'T' && nucleotide != 'C' && nucleotide != 'G') {
            throw std::invalid_argument("invalid nucleotide");
        }
        return this->counts.at(nucleotide);
    }
}  // namespace nucleotide_count
