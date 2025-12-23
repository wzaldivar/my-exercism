#ifndef DOCTOR_DATA_H
#define DOCTOR_DATA_H

#include <string>

namespace star_map
{
    enum System
    {
        BetaHydri,
        Sol,
        EpsilonEridani,
        AlphaCentauri,
        DeltaEridani,
        Omicron2Eridani
    };
}

namespace heaven
{
    struct Vessel
    {
        std::string name;
        int generation;
        star_map::System current_system;
        int busters;

        Vessel(const std::string &name,
               const int generation,
               const star_map::System current_system = star_map::System::Sol,
               const int busters = 0);

        Vessel replicate(const std::string &name);

        void make_buster();

        bool shoot_buster();
    };

    std::string get_older_bob(const Vessel &bob_a, const Vessel &bob_b);

    bool in_the_same_system(const Vessel &vessel_a, const Vessel &vessel_b);
}

#endif