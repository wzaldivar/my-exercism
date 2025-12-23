#include "pangram.h"

#include <set>

namespace pangram
{
    bool is_pangram(std::string str)
    {
        std::set<char> alphabet;

        for (char c = 'a'; c <= 'z'; ++c){
            alphabet.insert(c);
        } 

        size_t n = str.size();

        for (size_t i = 0; i < n; ++i){
           alphabet.erase( std::tolower(str.at(i)));
        }

        return alphabet.empty();
    }
} // namespace pangram
