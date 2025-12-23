#if !defined(CLOCK_H)
#define CLOCK_H

#include <string>

namespace date_independent
{
    namespace clock
    {
        struct at
        {
            int hours;
            int minutes;
            at(int hours, int minutes);
            at& plus(int minutes);
            operator std::string() const;
            bool operator==(const at& other) const;
            bool operator!=(const at& other) const;
        };
    }
} // namespace date_independent

#endif // CLOCK_H