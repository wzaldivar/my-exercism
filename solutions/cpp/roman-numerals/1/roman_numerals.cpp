#include "roman_numerals.h"

#include <sstream>

namespace roman_numerals
{
    std::string convert(int n)
    {
        std::stringstream ss;

        if (n < 10 || n % 10 == 0)
        {
            switch (n)
            {
            case 1:
                ss << "I";
                break;
            case 2:
                ss << "II";
                break;
            case 3:
                ss << "III";
                break;
            case 4:
                ss << "IV";
                break;
            case 5:
                ss << "V";
                break;
            case 6:
                ss << "VI";
                break;
            case 7:
                ss << "VII";
                break;
            case 8:
                ss << "VIII";
                break;
            case 9:
                ss << "IX";
                break;
            case 10:
                ss << "X";
                break;
            case 20:
                ss << "XX";
                break;
            case 30:
                ss << "XXX";
                break;
            case 40:
                ss << "XL";
                break;
            case 50:
                ss << "L";
                break;
            case 60:
                ss << "LX";
                break;
            case 70:
                ss << "LXX";
                break;
            case 80:
                ss << "LXXX";
                break;
            case 90:
                ss << "XC";
                break;
            case 100:
                ss << "C";
                break;
            case 200:
                ss << "CC";
                break;
            case 300:
                ss << "CCC";
                break;
            case 400:
                ss << "CD";
                break;
            case 500:
                ss << "D";
                break;
            case 600:
                ss << "DC";
                break;
            case 700:
                ss << "DCC";
                break;
            case 800:
                ss << "DCCC";
                break;
            case 900:
                ss << "CM";
                break;
            case 1000:
                ss << "M";
                break;
            case 2000:
                ss << "MM";
                break;
            case 3000:
                ss << "MMM";
                break;

            default:
                break;
            }
        }
        else if (n > 1000)
        {
            ss << convert(n - n % 1000) << convert(n % 1000);
        }
        else if (n > 100)
        {
            ss << convert(n - n % 100) << convert(n % 100);
        }
        else if (n > 10)
        {
            ss << convert(n - n % 10) << convert(n % 10);
        }
        return ss.str();
    }
} // namespace roman_numerals
