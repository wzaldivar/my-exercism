#include "say.h"

#include <stdexcept>
#include <sstream>

namespace say
{
    const unsigned long long LIMIT = 1000UL * 1000UL * 1000UL * 1000UL;

    std::string unit_in_english(unsigned char n)
    {
        switch (n)
        {
        case 1:
            return "one";
            break;
        case 2:
            return "two";
            break;
        case 3:
            return "three";
            break;
        case 4:
            return "four";
            break;
        case 5:
            return "five";
            break;
        case 6:
            return "six";
            break;
        case 7:
            return "seven";
            break;
        case 8:
            return "eight";
            break;
        case 9:
            return "nine";
            break;
        default:
            break;
        }

        return "";
    }

    std::string under_thousand_in_english(unsigned int n)
    {
        std::stringstream ss;

        unsigned char hundred = n / 100;

        if (hundred > 0)
        {
            ss << unit_in_english(hundred) << " hundred";
        }

        unsigned char two_digits = n % 100;

        if (hundred > 0 && two_digits > 0)
        {
            ss << " ";
        }

        if (two_digits < 20)
        {
            if (two_digits < 10)
            {
                ss << unit_in_english(two_digits);
            }
            else
            {
                switch (two_digits)
                {
                case 10:
                    ss << "ten";
                    break;
                case 11:
                    ss << "eleven";
                    break;
                case 12:
                    ss << "twelve";
                    break;
                case 13:
                    ss << "thirteen";
                    break;
                case 14:
                    ss << "fourteen";
                    break;
                case 15:
                    ss << "fifteen";
                    break;
                case 16:
                    ss << "sixteen";
                    break;
                case 17:
                    ss << "seventeen";
                    break;
                case 18:
                    ss << "eighteen";
                    break;
                case 19:
                    ss << "nineteen";
                    break;
                default:
                    break;
                }
            }
        }
        else
        {
            unsigned char decimal = two_digits / 10;

            switch (decimal)
            {
            case 2:
                ss << "twenty";
                break;
            case 3:
                ss << "thirty";
                break;
            case 4:
                ss << "forty";
                break;
            case 5:
                ss << "fifty";
                break;
            case 6:
                ss << "sixty";
                break;
            case 7:
                ss << "seventy";
                break;
            case 8:
                ss << "eighty";
                break;
            case 9:
                ss << "ninety";
                break;
            default:
                break;
            }

            unsigned char unit = two_digits % 10;

            if (unit > 0)
            {
                ss << "-" << unit_in_english(unit);
            }
        }

        return ss.str();
    }

    std::string in_english(unsigned long long n)
    {
        if (n >= LIMIT)
        {
            throw std::domain_error("too big");
        }

        if (n == 0ULL)
        {
            return "zero";
        }

        std::stringstream ss;

        unsigned int billion = n / (1000ULL * 1000ULL * 1000ULL);

        unsigned int million = n % (1000ULL * 1000ULL * 1000ULL) / (1000ULL * 1000ULL);

        unsigned int thousand = n % (1000ULL * 1000ULL) / 1000ULL;

        unsigned int under_thousand = n % 1000ULL;

        if (billion > 0)
        {
            ss << under_thousand_in_english(billion) << " billion";
        }

        if (million > 0)
        {
            if (billion > 0)
            {
                ss << " ";
            }
            ss << under_thousand_in_english(million) << " million";
        }

        if (thousand > 0)
        {
            if (billion > 0 || million > 0)
            {
                ss << " ";
            }
            ss << under_thousand_in_english(thousand) << " thousand";
        }

        if (under_thousand > 0)
        {
            if (billion > 0 || million > 0 || thousand > 0)
            {
                ss << " ";
            }

            ss << under_thousand_in_english(under_thousand);
        }

        return ss.str();
    }
} // namespace say
