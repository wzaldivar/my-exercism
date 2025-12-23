#if !defined(SERIES_H)
#define SERIES_H

#include <string>
#include <vector>

namespace series
{
    std::vector<std::string> slice(std::string const &str, std::size_t const n);
} // namespace series

#endif // SERIES_H