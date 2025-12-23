#include "food_chain.h"

#include <sstream>

namespace food_chain
{
    std::string swallow(int n)
    {
        std::stringstream ss;
        std::string item;

        switch (n)
        {
        case 1:
            item = "fly";
            break;
        case 2:
            item = "spider";
            break;
        case 3:
            item = "bird";
            break;
        case 4:
            item = "cat";
            break;
        case 5:
            item = "dog";
            break;
        case 6:
            item = "goat";
            break;
        case 7:
            item = "cow";
            break;
        case 8:
            item = "horse";
            break;
        default:
            break;
        }

        ss << "I know an old lady who swallowed a " << item << ".\n";
        return ss.str();
    }

    std::string joke(int n)
    {
        switch (n)
        {
        case 2:
            return "It wriggled and jiggled and tickled inside her.\n";
            break;
        case 3:
            return "How absurd to swallow a bird!\n";
            break;
        case 4:
            return "Imagine that, to swallow a cat!\n";
            break;
        case 5:
            return "What a hog, to swallow a dog!\n";
            break;
        case 6:
            return "Just opened her throat and swallowed a goat!\n";
            break;
        case 7:
            return "I don't know how she swallowed a cow!\n";
            break;
        default:
            break;
        }

        return "";
    }

    std::string reason(int n)
    {
        std::stringstream ss;

        switch (n)
        {
        case 7:
            ss << "She swallowed the cow to catch the goat.\n";
        case 6:
            ss << "She swallowed the goat to catch the dog.\n";
        case 5:
            ss << "She swallowed the dog to catch the cat.\n";
        case 4:
            ss << "She swallowed the cat to catch the bird.\n";
        case 3:
            ss << "She swallowed the bird to catch the spider that wriggled and jiggled and tickled inside her.\n";
        case 2:
            ss << "She swallowed the spider to catch the fly.\n";
            break;

        default:
            break;
        }

        return ss.str();
    }

    std::string ending(int n)
    {
        if (n == 8)
        {
            return "She's dead, of course!\n";
        }

        return "I don't know why she swallowed the fly. Perhaps she'll die.\n";
    }

    std::string verse(int n)
    {
        std::stringstream ss;

        ss << swallow(n);
        ss << joke(n);
        ss << reason(n);
        ss << ending(n);

        return ss.str();
    }

    std::string verses(int begin, int end)
    {
        std::stringstream ss;
        for (int i = begin; i <= end; ++i)
        {
            ss << verse(i) << '\n';
        }
        return ss.str();
    }

    std::string sing()
    {
        return verses(1, 8);
    }
} // namespace food_chain
