#include "beer_song.h"
#include <sstream>

namespace beer_song {
    std::string bottles(unsigned short n) {
        if (n == 0) { return "no more bottles"; }
        std::stringstream ss;
        ss << n << " bottle";
        if (n > 1) {
            ss << 's';
        }
        return ss.str();
    }

    std::string verse(unsigned short n) {
        std::stringstream ss;
        if (n == 0) {
            ss << "No more bottles of beer on the wall, no more bottles of beer.\n"
               << "Go to the store and buy some more, 99 bottles of beer on the wall.\n";
        } else {
            ss << bottles(n) << " of beer on the wall, " << bottles(n) << " of beer.\n"
               << "Take " << (n == 1 ? "it" : "one") << " down and pass it around, " << bottles(n - 1)
               << " of beer on the wall.\n";
        }
        return ss.str();
    }

    std::string sing(unsigned short begin, unsigned short end) {
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
