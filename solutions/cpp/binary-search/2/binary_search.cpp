#include "binary_search.h"

#include <stdexcept>

namespace binary_search
{
    std::size_t find(const std::vector<int> &data, const int &value)
    {
        std::size_t i = 0;
        std::size_t j = data.size();

        while (i < j)
        {
            std::size_t k = i + (j - i) / 2;

            if (data[k] == value)
            {
                return k;
            }

            if (data[k] < value)
            {
                i = k + 1;
            }
            else
            {
                j = k;
            }
        }

        throw std::domain_error("not found");
    }
} // namespace binary_search
