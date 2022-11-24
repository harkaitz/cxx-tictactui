#include "Board.hh"
#include <regex>
#include <string>
#include <stdexcept>

std::ostream& operator<<(std::ostream& out, const Board& b) {
    writeGameHeader((Board&)b, out);
    out << "%\n ";
    for (unsigned x=0; x<b.X; x++) {
        out << " " << (x+1);
    }
    out << "\n";
    for (unsigned y=0; y<b.Y; y++) {
        out << (char)((char)'a'+y);
        for (unsigned x=0; x<b.X; x++) {
            auto p = ((Board&)b).pieces[Coordinate(x,y)];
            if (p == "") {
                out << "| ";
            } else {
                out << "|" << p;
            }
        }
        out << "|\n";
    }
    out << ".\n";
    return out;
}

std::istream& operator>>(std::istream& is , Board& board) {
    std::string  line;
    unsigned int x,y;
    size_t       p;
    
    line = readGameHeader(board, is);
    if (line == ".") return is;

    y = 0;
    while (getline(is, line) && line != ".") {
        x = 0;
        p = 0;
        while (true) {
            p = line.find('|', p);
            if (p == std::string::npos) {
                break;
            }
            p++;
            if (p == line.length()) {
                break;
            }
            if (!isspace(line[p])) {
                board.pieces[Coordinate(x,y)] = line.substr(p, 1);
            }
            if (++x > board.X) {
                board.X = x;
            }
        }
        if (x > 0) {
            y++;
            if (y > board.Y) {
                board.Y = y;
            }
        }
    }
    return is;
}
