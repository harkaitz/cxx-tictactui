#ifndef TICTACTUI_TICTACTOE_HH
#define TICTACTUI_TICTACTOE_HH

#include "Board.hh"

class TicTacToe : public Board {
public:
    std::string            turn;
    std::string            winner;
    int                    getValue  (std::string player);
    inline std::string     getTurn   () { return this->turn; }
    inline void            setTurn   (std::string player) { this->turn = player; }
    std::string            getWinner ();
    std::list<std::string> getMoves  ();
    bool                   applyMove (std::string move);
    TicTacToe() {
        turn = "x";
        winner = "";
    }
    TicTacToe(TicTacToe *ttt) : Board(ttt) {
        turn   = ttt->turn;
        winner = ttt->winner;
    }
    Game* copyNew() {
        auto r = new TicTacToe(this);
        return r;
    }
};

#endif
