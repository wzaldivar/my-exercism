#include "collatz_conjecture.h"

#include <stdexcept>

namespace collatz_conjecture {
    int steps(int n) {
        if (n < 1) {
            throw std::domain_error("Can't be less than 1");
        }

        int counter = 0;

        while (n != 1) {
            if (n % 2 == 0) {
                n = n / 2;
            }
            else {
                n = 3 * n + 1;
            }
            counter++;
        }
        
        return counter;
    }
}  // namespace collatz_conjecture
