#include "difference_of_squares.h"

#include <cmath>

namespace difference_of_squares {
    long square_of_sum(const unsigned int n) {
        return pow(n, 2) * pow(n+1, 2) / 4;
    }

    long sum_of_squares(const unsigned int n) {
        return n * (n + 1) * (2 *n + 1) / 6;
    }

    long difference(const unsigned int n) {
        return square_of_sum(n) - sum_of_squares(n);
    }
}  // namespace difference_of_squares
