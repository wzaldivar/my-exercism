#include "clock.h"

#include <sstream>
#include <iomanip>

namespace date_independent
{
    namespace clock
    {
        struct clock_data
        {
            int hours;
            int minutes;
        };

        int apply_hours(int hours)
        {
            if (hours < 0)
            {
                hours = -hours;
                hours = hours % 24;
                hours = 24 - hours;
            }

            hours = hours % 24;
            return hours;
        }

        clock_data apply_minutes(int minutes)
        {
            clock_data data{0, minutes};
            if (data.minutes < 0)
            {
                data.minutes = -data.minutes;
                data.hours = -(data.minutes / 60);
                data.minutes = data.minutes % 60;
                if (data.minutes > 0)
                {
                    data.hours -= 1;
                }
                data.minutes = 60 - data.minutes;
            }
            else
            {
                data.hours = data.minutes / 60;
                data.minutes = data.minutes % 60;
            }

            return data;
        }

        at::at(int hours, int minutes)
        {
            clock_data data = apply_minutes(minutes);
            this->hours = apply_hours(hours + data.hours);
            this->minutes = data.minutes;
        }

        at::operator std::string() const
        {
            std::stringstream ss;

            ss << std::setw(2) << std::setfill('0') << this->hours << ":" << std::setw(2) << std::setfill('0') << this->minutes;

            return ss.str();
        }

        at &at::plus(int minutes)
        {
            clock_data data = apply_minutes(this->minutes + minutes);
            this->hours = apply_hours(this->hours + data.hours);
            this->minutes = data.minutes;

            return *this;
        }

        bool at::operator==(const at &other) const
        {
            return this->hours == other.hours && this->minutes == other.minutes;
        }

        bool at::operator!=(const at &other) const{
            return !operator==(other);
        }
    }
} // namespace date_independent
