#include "reverse_string.h"
#include <sstream>

namespace reverse_string
{
    std::string reverse_string(std::string str)
    {
        if (str.size() <= 1)
        {
            return str;
        }

        std::stringstream sstream;

        size_t n = str.size();

        for (size_t i = n - 1; i < n; --i)
        {
            sstream << str.at(i);
        }

        return sstream.str();
    }
} // namespace reverse_string
