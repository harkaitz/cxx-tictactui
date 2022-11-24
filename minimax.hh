#ifndef TICTACTUI_MINIMAX_HH
#define TICTACTUI_MINIMAX_HH

#include "Game.hh"
#include <map>

std::pair<int,std::string>
minimax(Game *_game, std::string _player, size_t _max_depth);

#endif
