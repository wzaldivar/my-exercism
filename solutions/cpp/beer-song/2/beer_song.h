#if !defined(BEER_SONG_H)
#define BEER_SONG_H

#include <string>

namespace beer_song {
    std::string verse(unsigned short n);

    std::string sing(unsigned short begin, unsigned short end = 0);
}  // namespace beer_song

#endif // BEER_SONG_H