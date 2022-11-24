#ifndef TICTACTUI_GAME_HH
#define TICTACTUI_GAME_HH

#include <string>
#include <list>
#include <regex>
#include <iostream>

class Game {
public:
    virtual int                    getValue  (std::string player) = 0;
    virtual std::string            getTurn   ()                   = 0;
    virtual void                   setTurn   (std::string player) = 0;
    virtual std::string            getWinner ()                   = 0;
    virtual std::list<std::string> getMoves  ()                   = 0;
    virtual bool                   applyMove (std::string move)   = 0;
    virtual void                   set       (std::string var, std::string val) {}
    virtual Game                  *copyNew   () = 0;
    virtual                        ~Game     () {}
};

inline void
writeGameHeader(Game &game, std::ostream& fp) {
    auto w = game.getWinner();
    if (w != "") {
        fp << "winner: " << w << "\n";
    }
    auto t = game.getTurn();
    if (t != "") {
        fp << "turn: " << t << "\n";
    }
}

inline std::string
readGameHeader(Game &game, std::istream& fp) {
    std::string line;
    size_t      pos;
    while (getline(fp, line)) {
        if (line == ".") {
            return ".";
        } else if (line == "%") {
            return "%";
        }
        pos = line.find(':');
        if (pos==std::string::npos) {
            continue;
        }
        auto var = line.substr(0, pos);
        auto val = line.substr(pos+1, std::string::npos);
        var = std::regex_replace(var, std::regex("^ +| +$|( ) +"), "$1");
        val = std::regex_replace(val, std::regex("^ +| +$|( ) +"), "$1");
        if (var == "turn") {
            game.setTurn(val);
        } else {
            game.set(var, val);
        }
    }
    return ".";
}

#endif
