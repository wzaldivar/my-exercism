#if !defined(SPACE_AGE_H)
#define SPACE_AGE_H

namespace space_age
{
    class space_age
    {
    private:
        unsigned long m_seconds;

        const double EARTH_YEAR_SECONDS = 31557600;

        const double MERCURY_EARTH_YEAR = 0.2408467;

        const double VENUS_EARTH_YEAR = 0.61519726;

        const double MARS_EARTH_YEAR = 1.8808158;

        const double JUPITER_EARTH_YEAR = 11.862615;

        const double SATURN_EARTH_YEAR = 29.447498;

        const double URANUS_EARTH_YEAR = 84.016846;

        const double NEPTUNE_EARTH_YEAR = 164.79132;

        double on_planet(const double earth_years) const;
    public:
        space_age(const unsigned long seconds);

        unsigned long seconds() const;

        double on_earth() const;

        double on_mercury() const;

        double on_venus() const;

        double on_mars() const;

        double on_jupiter() const;

        double on_saturn() const;

        double on_uranus() const;

        double on_neptune() const;
    };
} // namespace space_age

#endif // SPACE_AGE_H