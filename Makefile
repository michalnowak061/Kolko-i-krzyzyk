#
#  To sa opcje dla kompilacji
#
CXXFLAGS=-g -Iinc -Wall -pedantic -std=c++0x

__start__: TicTacToe
	./TicTacToe

Board.o: Board.hpp Board.cpp
	g++ -c ${CXXFLAGS} -o Board.o Board.cpp

main.o: main.cpp Player.hpp AdditionalFunctions.hpp
	g++ -c ${CXXFLAGS} -o main.o main.cpp

Player.o: Player.cpp Player.hpp Board.hpp MinMax.hpp
	g++ -c ${CXXFLAGS} -o Player.o Player.cpp

MinMax.o: MinMax.cpp MinMax.hpp Player.hpp
	g++ -c -o MinMax.o MinMax.cpp

AdditionalFunctions: AdditionalFunctions.cpp AdditionalFunctions.hpp Player.hpp Board.hpp
	g++ -c ${CXXFLAGS} -o AdditionalFunctions.o AdditionalFunctions.cpp 

TicTacToe: main.o Board.o Player.o MinMax.o AdditionalFunctions.o 
	g++ -Wall -pedantic -std=c++0x -o TicTacToe main.o Board.o Player.o MinMax.o AdditionalFunctions.o

clean:
	rm -f *.o *.dat TicTacToe

