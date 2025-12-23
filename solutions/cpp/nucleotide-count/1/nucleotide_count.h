#if !defined(NUCLEOTIDE_COUNT_H)
#define NUCLEOTIDE_COUNT_H

#include <map>
#include <string>

namespace nucleotide_count {
    class counter {
    private:
        std::map<char, int> counts;

    public:
        counter(std::string dna_chain);

        std::map<char, int> nucleotide_counts() const;

        int count(const char nucleotide) const;
    };
}  // namespace nucleotide_count

#endif // NUCLEOTIDE_COUNT_H