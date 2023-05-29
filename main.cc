#include <getopt.h>
#include "TicTacToe.hh"
#include "minimax.hh"

#define COPYRIGHT_LINE \
    "Bug reports, feature requests to https://harkadev.com/oss" "\n" \
    "Copyright (c) 2023 Harkaitz Agirre, harkaitz.aguirre@gmail.com" "\n" \
    ""

static char const help[] =
    "Usage: tictactoe OPTS..." "\n"
    ""                         "\n"
    "The classic TicTacToe game that follows the UNIX philosophy" "\n"
    "written in C++11"                        "\n"
    ""                                        "\n"
    "-g      : Create a new game."            "\n"
    "-m MOVE : Add move."                     "\n"
    "-M      : View all posible moves."       "\n"
    "-a      : Apply the specified moves."    "\n"
    "-i      : Calculate move using minimax." "\n"
    ""                                        "\n";

static char const board[] =
    "turn: x"   "\n"
    "%"         "\n"
    "  1 2 3"   "\n"
    "a| | | |"  "\n"
    "b| | | |"  "\n"
    "c| | | |"  "\n"
    "."         "\n";

int main (int _argc, char *_argv[]) {

    TicTacToe              ttt;
    std::list<std::string> moves;
    
    bool opt_create_new_game = false;
    bool opt_calculate_moves = false;
    bool opt_apply_move      = false;

    for(;;) {
        int opt = getopt(_argc, _argv, "hgm:Mai");
        if (opt == -1)  break;
        if (opt == '?') return 1;
        switch (opt) {
        case 'h': std::cout << help << COPYRIGHT_LINE; return 1;
        case 'g': opt_create_new_game = true; break;
        case 'm': moves.push_back(optarg);    break;
        case 'i': moves.push_back("ai");      break;
        case 'M': opt_calculate_moves = true; break;
        case 'a': opt_apply_move = true;      break;
        }
    }

    if (opt_create_new_game) {
        std::istringstream buf(board);
        buf >> ttt;
    } else {
        std::cin >> ttt;
    }

    for (auto m : moves) {
        if (m == "minimax" || m == "ai") {
            auto r = minimax(&ttt, ttt.getTurn(), 10);
            m = r.second;
            std::cout << "value: " << r.first << "\n";
        }
        if (opt_apply_move) {
            if (!ttt.applyMove(m)) {
                std::cerr << "Invalid move: [" << m << "]\n";
            }
        } else {
            std::cout << "move: " << m << "\n";
        }
    }
    moves.clear();
    
    if (opt_calculate_moves) {
        for (auto m : ttt.getMoves()) {
            std::cout << "move: " << m << "\n";
        }
    }

    std::cout << ttt;
    
    return 0;
}
