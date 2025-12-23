#if !defined(PHONE_NUMBER_H)
#define PHONE_NUMBER_H

#include <string>

namespace phone_number
{
    struct phone_number
    {
        phone_number(std::string const &str);
        std::string number() const;
        std::string area_code() const;

        operator std::string() const;
    private:
        std::string const phone_str;
        std::string const number_str;
    };
} // namespace phone_number

#endif // PHONE_NUMBER_H