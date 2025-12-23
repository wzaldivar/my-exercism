#include "secret_handshake.h"
#include <algorithm>

namespace secret_handshake
{
    std::vector<std::string> commands(int8_t key)
    {
        std::vector<std::string> result;

        bool reverse = key >= 16;
        key = key % 16;

        if (key >= 8)
        {
            result.push_back("jump");
        }
        key = key % 8;

        if (key >= 4)
        {
            result.push_back("close your eyes");
        }
        key = key % 4;

        if (key >= 2)
        {
            result.push_back("double blink");
        }
        key = key % 2;

        if (key == 1)
        {
            result.push_back("wink");
        }

        if (!reverse)
        {
            std::reverse(result.begin(), result.end());
        }
        return result;
    }
} // namespace secret_handshake
