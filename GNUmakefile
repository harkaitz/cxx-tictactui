DESTDIR =
PREFIX  =/usr/local
CXX     =c++
CXXFLAGS=-Wall -std=c++17 -g -O3
PROGRAMS=tictactoe$(EXE)
SOURCES =TicTacToe.cc Board.cc minimax.cc
HEADERS =TicTacToe.hh Board.hh minimax.hh Game.hh
FLAGS_PX=$(CXXFLAGS) $(CPPFLAGS) -DPREFIX='"$(PREFIX)"' $(LDFLAGS) $(LIBS)

all: $(PROGRAMS)
clean:
	rm -f $(PROGRAMS)
install: $(PROGRAMS)
	mkdir -p $(PREFIX)/bin
	cp $(PROGRAMS) $(PREFIX)/bin
update:

tictactoe$(EXE): main.cc $(SOURCES) $(HEADERS)
	$(CXX) -o $@ main.cc $(SOURCES) $(FLAGS_PX)


## -- license --
install: install-license
install-license: LICENSE
	@echo 'I share/doc/cxx-tictactui/LICENSE'
	@mkdir -p $(DESTDIR)$(PREFIX)/share/doc/cxx-tictactui
	@cp LICENSE $(DESTDIR)$(PREFIX)/share/doc/cxx-tictactui
## -- license --
