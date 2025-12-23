#include "beer_song.h"
#include <sstream>

namespace beer_song {
    std::string verse(int n) {
        std::stringstream ss;
        if (n == 0) {
            ss << "No more bottles of beer on the wall, no more bottles of beer.\n"
               << "Go to the store and buy some more, 99 bottles of beer on the wall.\n";
        } else if (n == 1) {
            ss << "1 bottle of beer on the wall, 1 bottle of beer.\n"
               << "Take it down and pass it around, no more bottles of beer on the wall.\n";
        } else {
            ss << n << " bottles of beer on the wall, " << n << " bottles of beer.\n"
               << "Take one down and pass it around, " << n - 1 << " bottles of beer on the wall.\n";
        }
        return ss.str();
    }

    std::string sing(int begin, int end) {
        std::stringstream ss;

        int n = begin;

        while (n <= begin && n >= end) {
            ss << verse(n);
            if (n > end) {
                ss << "\n";
            }
            --n;
        }

        return ss.str();
    }
}  // namespace beer_song
