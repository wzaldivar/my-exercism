#if !defined(GRADE_SCHOOL_H)
#define GRADE_SCHOOL_H

#include <map>
#include <vector>
#include <string>

namespace grade_school
{
    class school
    {
    private:
        std::map<int, std::vector<std::string> > m_roster;

    public:
        school();

        std::map<int, std::vector<std::string> > roster() const;

        void add(const std::string name, const int grade);

        std::vector<std::string> grade(const int grade) const;
    };
} // namespace grade_school

#endif // GRADE_SCHOOL_H