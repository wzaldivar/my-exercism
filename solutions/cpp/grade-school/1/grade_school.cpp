#include "grade_school.h"

#include <algorithm>

namespace grade_school
{
    school::school() {}

    std::map<int, std::vector<std::string> > school::roster() const
    {
        return this->m_roster;
    }

    void school::add(const std::string name, const int grade)
    {
        this->m_roster[grade].push_back(name);
        std::sort(this->m_roster[grade].begin(), this->m_roster[grade].end());
    }

    std::vector<std::string> school::grade(const int grade) const
    {
        if (this->m_roster.find(grade) == this->m_roster.end())
        {
            return std::vector<std::string>();
        }

        return this->m_roster.at(grade);
    }
} // namespace grade_school
