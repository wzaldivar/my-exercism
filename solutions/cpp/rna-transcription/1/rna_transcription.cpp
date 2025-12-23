#include "rna_transcription.h"

#include <sstream>

namespace rna_transcription {
  char to_rna(const char c) {
    char rna;

    switch(c) {
        case 'A':
            rna = 'U';
            break;
        case 'T':
            rna = 'A';
            break;
        case 'C':
            rna = 'G';
            break;
        case 'G':
            rna = 'C';
            break;
    }

    return rna;
  }

  std::string to_rna(const std::string s) {
    std::stringstream rna;
    
    for(size_t i = 0; i < s.size(); ++i) {
        rna << to_rna(s.at(i));
    }
    
    return rna.str();
  }
}  // namespace rna_transcription
