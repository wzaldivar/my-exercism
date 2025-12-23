#include "atbash_cipher.h"

#include <sstream>

namespace atbash_cipher
{
    char encode(const char c)
    {
        if ('a' <= c && 'z' >= c)
        {
            return 'z' - c + 'a';
        }

        if ('A' <= c && 'Z' >= c)
        {
            return 'z' - c + 'A';
        }

        if ('0' <= c && '9' >= c)
        {
            return c;
        }

        return '\0';
    }

    std::string encode(const std::string &s)
    {
        std::stringstream ss;
        unsigned int i = 0;
        for (char c : s)
        {
            c = encode(c);
            if (c != '\0')
            {
                if (i > 0 && i % 5 == 0)
                {
                    ss << ' ';
                }
                ss << c;
                ++i;
            }
        }
        return ss.str();
    }

    std::string decode(const std::string &s)
    {
        std::stringstream ss;
        for (char c : s)
        {
            c = encode(c);
            if (c != '\0')
            {
                ss << c;
            }
        }
        return ss.str();
    }
} // namespace atbash_cipher
