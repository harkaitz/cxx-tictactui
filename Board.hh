#ifndef TICTACTUI_BOARD_HH
#define TICTACTUI_BOARD_HH

#include "Game.hh"
#include <map>
#include <iostream>

typedef std::pair<unsigned,unsigned> Coordinate;

class Board : public Game {
public:
    unsigned int                     X,Y;
    std::map<Coordinate,std::string> pieces;
    Board() {
        X = 0, Y = 0, pieces = {};
    }
    Board(const Board *b) {
        X = b->X;
        Y = b->Y;
        pieces = b->pieces;
    }
    
};

std::ostream& operator<<(std::ostream& out, const Board& f);
std::istream& operator>>(std::istream& is ,       Board& t);

static inline std::string to_string(const Coordinate _c) {
    char mv[3] = {
        (char)('a'+std::get<1>(_c)),
        (char)('1'+std::get<0>(_c)),
        '\0'
    };
    return std::string(mv);
}

static inline Coordinate parse_coordinate(std::string _s) {
    return Coordinate(_s[1]-'1', _s[0]-'a');
}

#endif
