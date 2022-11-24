#include "TicTacToe.hh"
#include <array>
#include <exception>

const Coordinate WIN_CASES[8][3] = {
    { {0,0}, {0,1}, {0,2} },
    { {1,0}, {1,1}, {1,2} },
    { {2,0}, {2,1}, {2,2} },

    { {0,0}, {1,0}, {2,0} },
    { {0,1}, {1,1}, {2,1} },
    { {0,2}, {1,2}, {2,2} },

    { {0,0}, {1,1}, {2,2} },
    { {2,0}, {1,1}, {0,2} },
};

int
TicTacToe::getValue(std::string player) {
    auto w = this->getWinner();
    if (w == "") {
        return 0;
    } else if (w == player) {
        return 1;
    } else {
        return -1;
    }
}

std::string
TicTacToe::getWinner() {
    if (this->winner == "") {
        for (auto line : WIN_CASES) {
            auto p1 = this->pieces[line[0]];
            auto p2 = this->pieces[line[1]];
            auto p3 = this->pieces[line[2]];
            if (p1 != "" && p1 == p2 && p2 == p3) {
                this->winner = std::string(p1);
                this->turn   = "";
            }
        }
    }
    return this->winner;
}

std::list<std::string>
TicTacToe::getMoves() {
    auto w = this->getWinner();
    auto l = std::list<std::string>();
    
    if (w != "") {
        return {};
    }

    for (unsigned x = 0; x<this->X; x++) {
        for (unsigned y=0; y<this->Y; y++) {
            auto p = Coordinate(x,y);
            if (this->pieces[p] == "") {
                l.push_back(to_string(p));
            }
        }
    }

    return l;
}

bool
TicTacToe::applyMove(std::string move) {
    auto p = parse_coordinate(move);
    auto x = std::get<0>(p);
    auto y = std::get<1>(p);
    auto t = this->getTurn();
    if (t == "" || x >= this->X || y >= this->Y) {
        return false;
    }
    auto s = this->pieces[p];
    if (s != "") {
        return false;
    }
    this->pieces[p] = t;
    if (t == "x") {
        this->turn = "o";
        return true;
    } else if (t == "o") {
        this->turn = "x";
        return true;
    } else {
        return false;
    }
}


