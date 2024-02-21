PROJECT =cxx-tictactui
VERSION =1.0.0
DESTDIR =
PREFIX  =/usr/local
CXX     =c++ -Wall -std=c++17 -O3
PROGRAMS=tictactoe$(EXE)
SOURCES =TicTacToe.cc Board.cc minimax.cc
HEADERS =TicTacToe.hh Board.hh minimax.hh Game.hh
##
FLAGS_PX=$(CXXFLAGS) $(CPPFLAGS) -DPREFIX='"$(PREFIX)"' $(LDFLAGS) $(LIBS)
##
all: $(PROGRAMS)
clean:
	rm -f $(PROGRAMS)
install: $(PROGRAMS)
	@mkdir -p $(DESTDIR)$(PREFIX)/bin
	cp $(PROGRAMS) $(DESTDIR)$(PREFIX)/bin
tictactoe$(EXE): main.cc $(SOURCES) $(HEADERS)
	$(CXX) -o $@ main.cc $(SOURCES) $(FLAGS_PX)
## -- BLOCK:license --
install: install-license
install-license: 
	@mkdir -p $(DESTDIR)$(PREFIX)/share/doc/$(PROJECT)
	cp LICENSE  $(DESTDIR)$(PREFIX)/share/doc/$(PROJECT)
## -- BLOCK:license --
