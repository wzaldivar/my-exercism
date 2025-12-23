#if !defined(ALLERGIES_H)
#define ALLERGIES_H

#include <string>
#include <unordered_set>

namespace allergies
{
    class allergy_test
    {
    private:
        std::unordered_set<std::string> allergies;

    public:
        allergy_test(const int score);
        bool is_allergic_to(const std::string &allergen);
        std::unordered_set<std::string> get_allergies();
    };
} // namespace allergies

#endif // ALLERGIES_H