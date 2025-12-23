#if !defined(QUEEN_ATTACK_H)
#define QUEEN_ATTACK_H

#include <utility>
#include <string>

namespace queen_attack {
    class chess_board {
        public:
            typedef std::pair<int, int> queen_pos_t;
        
            chess_board();
            chess_board(queen_pos_t queen_white, queen_pos_t queen_black);

            queen_pos_t white() const;
            queen_pos_t black() const;

            bool can_attack() const;

            operator std::string() const;

        private:
            queen_pos_t m_queen_white;
            queen_pos_t m_queen_black;    
    };
}  // namespace queen_attack

#endif // QUEEN_ATTACK_H