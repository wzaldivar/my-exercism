#include "bob.h"

namespace bob
{
    bool is_question(const std::string &str)
    {
        std::size_t n = str.length();
        std::size_t i = n - 1;
        while (i < n)
        {
            if (str[i] != ' ' && str[i] != '\t' && str[i] != '\n' && str[i] != '\r')
            {
                if (str[i] == '?')
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }
            --i;
        }
        return false;
    }

    bool is_yell(const std::string &str)
    {
        bool yell = false;
        for (char c : str)
        {
            if ('A' <= c && c <= 'Z')
            {
                yell = true;
            }
            else if ('a' <= c && c <= 'z')
            {
                return false;
            }
        }
        return yell;
    }

    bool is_silence(const std::string &str)
    {
        for (char c : str)
        {
            if (c != ' ' && c != '\t' && c != '\n' && c != '\r')
            {
                return false;
            }
        }
        return true;
    }

    std::string hey(const std::string &str)
    {
        bool silence = is_silence(str);

        if (silence)
        {
            return "Fine. Be that way!";
        }

        bool question = is_question(str);
        bool yell = is_yell(str);

        if (yell && question)
        {
            return "Calm down, I know what I'm doing!";
        }

        if (question)
        {
            return "Sure.";
        }

        if (yell)
        {
            return "Whoa, chill out!";
        }

        return "Whatever.";
    }
} // namespace bob
