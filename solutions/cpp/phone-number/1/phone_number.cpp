#include "phone_number.h"

#include <sstream>
#include <stdexcept>

namespace phone_number
{
    static std::string clean(std::string const &str)
    {
        std::stringstream ss;
        std::size_t len = 0;

        for (char c : str)
        {
            if (len == 0 && (c == '+' || c == '1' || c == ' ' || c == '\t'))
            {
                continue;
            }
            ss << c;
            len++;
        }

        return ss.str();
    }

    static std::string translate(std::string const &str)
    {
        std::stringstream ss;
        bool country_code = false;
        std::size_t len = 0;

        for (char c : str)
        {
            if ('0' > c || c > '9')
            {
                continue;
            }

            if (c == '0' && (len == 0 || len == 3))
            {
                throw std::domain_error("Invalid phone number");
            }

            if (c == '1' && len == 0)
            {
                if (!country_code)
                {
                    country_code = true;
                    continue;
                }
                else
                {
                    throw std::domain_error("Invalid phone number");
                }
            }

            if (c == '1' && len == 3)
            {
                throw std::domain_error("Invalid phone number");
            }

            ss << c;
            len++;

            if (len > 10)
            {
                throw std::domain_error("Invalid phone number");
            }
        }

        if (len < 10)
        {
            throw std::domain_error("Invalid phone number");
        }

        return ss.str();
    }

    phone_number::phone_number(std::string const &str) : phone_str(clean(str)), number_str(translate(str))
    {
    }

    std::string phone_number::number() const
    {
        return this->number_str;
    }

    std::string phone_number::area_code() const
    {
        return this->number_str.substr(0, 3);
    }

    phone_number::operator std::string() const
    {
        return this->phone_str;
    }
} // namespace phone_number
