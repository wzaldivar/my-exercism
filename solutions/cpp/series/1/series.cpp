#include "series.h"

#include <stdexcept>

namespace series
{
    std::vector<std::string> slice(std::string const &str, std::size_t const n)
    {
        std::vector<std::string> subs;
        std::size_t len = str.length();
        std::size_t i = 0;

        if (n == 0){
            throw std::domain_error("invalid slice");
        }

        if (len < n)
        {
            throw std::domain_error("invalid slice");
        }

        while (i + n <= len)
        {
            subs.push_back(str.substr(i, n));
            ++i;
        }

        return subs;
    }
} // namespace series
