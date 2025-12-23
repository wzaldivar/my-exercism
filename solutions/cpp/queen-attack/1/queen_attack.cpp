#include "queen_attack.h"

#include <sstream>
#include <stdexcept>

namespace queen_attack
{
    chess_board::chess_board() : chess_board(std::make_pair(0, 3), std::make_pair(7, 3)) {}

    chess_board::chess_board(queen_pos_t queen_white, queen_pos_t queen_black)
    {
        if (queen_white.first == queen_black.first && queen_white.second == queen_black.second)
        {
            throw std::domain_error("can't be in the same possition");
        }

        this->m_queen_white = queen_white;
        this->m_queen_black = queen_black;
    }

    chess_board::queen_pos_t chess_board::white() const
    {
        return this->m_queen_white;
    }

    chess_board::queen_pos_t chess_board::black() const
    {
        return this->m_queen_black;
    }

    bool chess_board::can_attack() const
    {
        return (this->m_queen_white.first == this->m_queen_black.first) ||
               (this->m_queen_white.second == this->m_queen_black.second) ||
               abs(this->m_queen_white.first - this->m_queen_black.first) == abs(this->m_queen_white.second - this->m_queen_black.second);
    }

    chess_board::operator std::string() const
    {
        std::stringstream stream;

        for (int row = 0; row < 8; ++row)
        {
            for (int col = 0; col < 8; ++col)
            {
                if (this->m_queen_white.first == row && this->m_queen_white.second == col)
                {
                    stream << "W";
                }
                else if (this->m_queen_black.first == row && this->m_queen_black.second == col)
                {
                    stream << "B";
                }
                else
                {
                    stream << "_";
                }
                if (col < 7)
                {
                    stream << " ";
                }
            }
            stream << std::endl;
        }

        return stream.str();
    }

} // namespace queen_attack
