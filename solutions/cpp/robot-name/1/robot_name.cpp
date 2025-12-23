#include "robot_name.h"

#include <random>
#include <sstream>

namespace robot_name
{
    std::string get_random_name()
    {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> alpha('A', 'Z');
        std::uniform_int_distribution<> num(0, 9);

        std::stringstream ss;

        char a = alpha(gen);
        char b = alpha(gen);
        int x = num(gen);
        int y = num(gen);
        int z = num(gen);

        ss << a << b << x << y << z;

        return ss.str();
    }

    robot::robot() : m_name("")
    {
        this->rename();
    }

    void robot::reset()
    {
        this->rename();
    }

    std::string robot::name() const
    {
        return this->m_name;
    }

    void robot::rename()
    {
        std::string new_name;
        do
        {
            new_name = get_random_name();
        } while (names.find(new_name) != names.end());

        this->m_name = new_name;
        names.insert(this->m_name);
    }
} // namespace robot_name
