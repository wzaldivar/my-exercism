#include "space_age.h"

namespace space_age
{
    space_age::space_age(const unsigned long seconds)
    {
        this->m_seconds = seconds;
    }

    unsigned long space_age::seconds() const
    {
        return this->m_seconds;
    }

    double space_age::on_earth() const
    {
        return this->m_seconds / space_age::EARTH_YEAR_SECONDS;
    }

    double space_age::on_planet(const double earth_years) const
    {
        return this->on_earth() / earth_years;
    }

    double space_age::on_mercury() const
    {
        return this->on_planet(MERCURY_EARTH_YEAR);
    }

    double space_age::on_venus() const
    {
        return this->on_planet(VENUS_EARTH_YEAR);
    }

    double space_age::on_mars() const
    {
        return this->on_planet(MARS_EARTH_YEAR);
    }

    double space_age::on_jupiter() const
    {
        return this->on_planet(JUPITER_EARTH_YEAR);
    }

    double space_age::on_saturn() const
    {
        return this->on_planet(SATURN_EARTH_YEAR);
    }

    double space_age::on_uranus() const
    {
        return this->on_planet(URANUS_EARTH_YEAR);
    }

    double space_age::on_neptune() const
    {
        return this->on_planet(NEPTUNE_EARTH_YEAR);
    }
} // namespace space_age
