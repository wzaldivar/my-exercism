#include "allergies.h"
#include <unordered_map>

namespace allergies
{
    allergy_test::allergy_test(const int score)
    {
        std::unordered_map<int, std::string> allergens{
            {1, "eggs"},
            {2, "peanuts"},
            {4, "shellfish"},
            {8, "strawberries"},
            {16, "tomatoes"},
            {32, "chocolate"},
            {64, "pollen"},
            {128, "cats"},
        };

        for (auto allergen : allergens)
        {
            if (score & allergen.first)
            {
                this->allergies.emplace(allergen.second);
            }
        }
    }

    bool allergy_test::is_allergic_to(const std::string &allergen)
    {
        return this->allergies.find(allergen) != this->allergies.end();
    }

    std::unordered_set<std::string> allergy_test::get_allergies()
    {
        return this->allergies;
    }
} // namespace allergies
