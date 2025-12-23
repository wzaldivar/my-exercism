#include "raindrops.h"

#include <sstream>

namespace raindrops
{
    std::string convert(unsigned int drops)
    {
        std::stringstream ss;

        bool factor_found = false;

        if (drops % 3 == 0)
        {
            factor_found = true;
            ss << "Pling";
        }

        if (drops % 5 == 0)
        {
            factor_found = true;
            ss << "Plang";
        }

        if (drops % 7 == 0)
        {
            factor_found = true;
            ss << "Plong";
        }

        if (!factor_found)
        {
            ss << drops;
        }

        return ss.str();
    }
} // namespace raindrops
