#include "Game.hh"
#include <climits> /* Note: INT_{MIN,MAX} */

std::pair<int,std::string>
minimax(Game *_game, std::string _player, size_t _max_depth) {
    std::string            turn      = _game->getTurn();
    bool                   maximizer = (_player == turn);
    int                    value     = (maximizer)?INT_MIN:INT_MAX;
    std::string            value_mv  = "";
    std::list<std::string> moves     = _game->getMoves();
    if (moves.size()==0) {
        return std::pair<int,std::string>(_game->getValue(_player), "");
    }
    for (auto mv : moves) {
        if (value_mv == "") {
            value_mv = mv;
        }
        Game *g = _game->copyNew();
        if (!g) {
            break;
        }
        if (!g->applyMove(mv)) {
            delete g;
            continue;
        }
        auto value_new = minimax(g, _player, _max_depth-1).first;
        free(g);
        if ( (maximizer == true  && value_new > value) ||
             (maximizer == false && value_new < value) ) {
            value    = value_new;
            value_mv = mv;
        }
    }
    return std::pair<int,std::string>(value, value_mv);
}
