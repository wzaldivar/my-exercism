#include <string>
#include <stdexcept>
#include "hamming.h"

namespace hamming {
    int compute(const std::string str1, const std::string str2) {
        if (str1.size() != str2.size()) {
            throw std::domain_error("different lengths");
        }

        size_t n = str1.size();

        int hamming = 0;

        for (size_t i = 0; i < n; ++i) {
            if (str1[i] != str2[i]) {
                hamming++;
            }
        }

        return hamming;
    }
}  // namespace hamming
