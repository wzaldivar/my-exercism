#include <string>
#include <sstream>

namespace log_line
{
    std::string message(const std::string &log_line)
    {
        std::size_t pos = log_line.find(' ');
        return log_line.substr(pos + 1);
    }

    std::string log_level(const std::string &log_line)
    {
        std::size_t pos = log_line.find(']');
        return log_line.substr(1, pos - 1);
    }

    std::string reformat(const std::string &log_line)
    {
        std::stringstream ss;
        ss << message(log_line) << " (" << log_level(log_line) << ")";
        return ss.str();
    }

} // namespace log_line
