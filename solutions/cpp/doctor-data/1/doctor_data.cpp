#include "doctor_data.h"

namespace heaven
{
    Vessel::Vessel(const std::string &name,
                   const int generation,
                   const star_map::System current_system,
                   const int busters) : name(name),
                                        generation(generation),
                                        current_system(current_system),
                                        busters(busters) {}

    Vessel Vessel::replicate(const std::string &name)
    {
        return {name, this->generation + 1, this->current_system, this->busters};
    }

    void Vessel::make_buster()
    {
        this->busters++;
    }

    bool Vessel::shoot_buster()
    {
        if (this->busters == 0)
        {
            return false;
        }

        this->busters--;
        return true;
    }

    std::string get_older_bob(const Vessel &bob_a, const Vessel &bob_b)
    {
        return bob_b.generation < bob_a.generation ? bob_b.name : bob_a.name;
    }

    bool in_the_same_system(const Vessel &vessel_a, const Vessel &vessel_b)
    {
        return vessel_a.current_system == vessel_b.current_system;
    }
}