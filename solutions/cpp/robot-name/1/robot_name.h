#if !defined(ROBOT_NAME_H)
#define ROBOT_NAME_H

#include <string>
#include <unordered_set>

namespace robot_name
{
    static std::unordered_set<std::string> names;

    std::string get_random_name();

    class robot
    {
    private:
        std::string m_name;

        void rename();

    public:
        robot();

        std::string name() const;

        void reset();
    };

} // namespace robot_name

#endif // ROBOT_NAME_H