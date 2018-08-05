#if !defined(QUEEN_ATTACK_H)
#define QUEEN_ATTACK_H

#include <stdexcept>
#include <string>
#include <utility>

namespace queen_attack {
    using position = std::pair<int, int>;

    class chess_board {
    public:
        chess_board():
            whiteQueen(std::make_pair(0, 3)),
            blackQueen(std::make_pair(7, 3)) {}

        chess_board(const position &white, const position &black):
            whiteQueen(white),
            blackQueen(black) {
                if (white == black)
                    throw std::domain_error("queens cannot occupy the same square at the same time");
            }

        const position &white(void) const {
            return whiteQueen;
        }

        const position &black(void) const {
            return blackQueen;
        }

        bool can_attack(void) const {
            int rowDelta = whiteQueen.first - blackQueen.first;
            int colDelta = whiteQueen.second - blackQueen.second;

            return rowDelta == 0 || colDelta == 0 || abs(rowDelta) == abs(colDelta);
        }

        operator std::string() const {
            std::string board = "_ _ _ _ _ _ _ _\n";

            const size_t rowLength = board.length();

            board += board;
            board += board;
            board += board;

            board[whiteQueen.first * rowLength + whiteQueen.second * 2] = 'W';
            board[blackQueen.first * rowLength + blackQueen.second * 2] = 'B';

            return board;
        }

    private:
        position whiteQueen;
        position blackQueen;
    };
}

#endif

//
//  This exercise seems rather trivial
//
//  There is little scope for variation, nonetheless, people tried hard.
//
//  Most used std::pair (the API almost forced it) but one used 4 variables
//  and one went so far as to define their own class.
//
//  The readme told you to check the queens were not on the same square and
//  this was tested but two solutions had checks that the queens were on the
//  board.
//
//  For drawing the board, most used a static array and superposed the queens.
//  One built up the board with a loop.  Three built the board from scratch,
//  inserting the queens in the process.  One of these used a stringstream.
//
//  The queen attack calculation showed most variation.  One calculated all
//  four possibilities and then did the if.  The others tended to compare,
//  then calculate the delta.  One did the delta as a ratio.
//
//  Performance is not an issue here but how clear the code is.  I think mine
//  is as good as any.  Next time I might put the abs around the delta
//  calculation.
//
